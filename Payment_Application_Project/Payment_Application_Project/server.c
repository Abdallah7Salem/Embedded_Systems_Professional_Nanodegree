#include "server.h"
#include <stdio.h>
#include <stdint.h>


ST_accountsDB_t accounts_arr[255] = {	// This is the database for the valid accounts in the server
	{3500, "42419641654165465"},      // account 0
	{4253.5, "45973241569753489"},	// account 1
	{2530, "98437896153374697"},		// account 2
	{4700, "123456789123456789"},		// account 3
	{50000, "12345678912345678"},		// account 4
	{1565.500, "123456789123456456"},	// account 5
	{4541.796, "789456123789456123"},	// account 6
	{1333.700, "456132789456789123"},   // account 7
};

ST_transaction_t transactions_arr[255] = { 0 };
int g_variable; // This variable is used in the isAmountAvailable function 
				// to have the value of i which is the index of the user in the database


EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	EN_serverError_t server_return;
	server_return = isValidAccount(&transData->cardHolderData);

	if (server_return == DECLINED_STOLEN_CARD)
	{
		printf("\nDeclined, Invalid Account !");
		return;
	}

	server_return = isAmountAvailable(&transData->terminalData);

	if (server_return == LOW_BALANCE)
	{
		printf("\nYou don't have enough balance !\n");
		return;
	}

	saveTransaction(transData);

}

EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		if (!strcmp(cardData->primaryAccountNumber, &accounts_arr[i].primaryAccountNumber))
		{
			if (i == 7)  // Card 7 is stolen and reported by the user 
			{
				return DECLINED_STOLEN_CARD;
			}
			g_variable = i;
			return SERVER_OK;
		}
	}
	return DECLINED_STOLEN_CARD;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{

	if (termData->transAmount > accounts_arr[g_variable].balance)
	{
		return LOW_BALANCE;
	}
	
	return SERVER_OK;
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	transData->transactionSequenceNumber = 0; // Initial state for sequence number (for the first user)

	/*================= Card information to transactions Array ==================*/
	strcpy(transactions_arr[transData->transactionSequenceNumber].cardHolderData.cardHolderName, transData->cardHolderData.cardHolderName);
	printf("\nYour Name: %s", transactions_arr[transData->transactionSequenceNumber].cardHolderData.cardHolderName);

	strcpy(transactions_arr[transData->transactionSequenceNumber].cardHolderData.primaryAccountNumber, transData->cardHolderData.primaryAccountNumber);
	printf("\nYour Primary Account Number: %s", transactions_arr[transData->transactionSequenceNumber].cardHolderData.primaryAccountNumber);

	strcpy(transactions_arr[transData->transactionSequenceNumber].cardHolderData.cardExpirationDate, transData->cardHolderData.cardExpirationDate);
	printf("\nYour card's expiry date: %s", transactions_arr[transData->transactionSequenceNumber].cardHolderData.cardExpirationDate);

	/*================= Terminal information to transactions Array =================*/
	strcpy(transactions_arr[transData->transactionSequenceNumber].terminalData.transactionDate, transData->terminalData.transactionDate);
	printf("\nThe transition date (current): %s", transactions_arr[transData->transactionSequenceNumber].terminalData.transactionDate);

	transactions_arr[transData->transactionSequenceNumber].terminalData.maxTransAmount = transData->terminalData.maxTransAmount;
	printf("\nMaximum Transaction Amount: %0.2f", transactions_arr[transData->transactionSequenceNumber].terminalData.maxTransAmount);

	transactions_arr[transData->transactionSequenceNumber].terminalData.transAmount = transData->terminalData.transAmount;
	printf("\nThe transaction Amount: %0.2f", transactions_arr[transData->transactionSequenceNumber].terminalData.transAmount);

	printf("\nYour balance before transaction: %0.2f", accounts_arr[g_variable].balance);

	accounts_arr[g_variable].balance -= transData->terminalData.transAmount;
	printf("\nUpdated Balance: %0.2f\n", accounts_arr[g_variable].balance);

	transData->transState = APPROVED;

	// Increment sequence number by 1 after transaction is done for a user
	transData->transactionSequenceNumber++;
}
