#include "app.h"
#include "card.h"
#include "terminal.h"
#include "server.h"


ST_cardData_t cardData_obj;
ST_terminalData_t termData_obj;
ST_transaction_t transData_obj;

ST_cardData_t* cardData;
ST_terminalData_t* termData;
ST_transaction_t* transData;


void appStart(void)
{
	/*============= Initializations ==========*/
	cardData = &cardData_obj;
	termData = &termData_obj;
	transData = &transData_obj;


	EN_cardError_t card_return;
	EN_terminalError_t terminal_return;
	EN_serverError_t server_return;
	EN_transState_t transaction_return;

	card_return = getCardHolderName(cardData);

	if (card_return == WRONG_NAME)
	{
		printf("\nDeclined, Please Enter name between 20, 24 characters !");
		return;
	}

	strcpy(transData->cardHolderData.cardHolderName, cardData->cardHolderName);

	card_return = getCardExpiryDate(cardData);

	if (card_return == WRONG_EXP_DATE)
	{
		printf("\nDeclined, Please Enter expiry date in the format MM/YY");
		return;
	}

	strcpy(transData->cardHolderData.cardExpirationDate, cardData->cardExpirationDate);

	card_return = getCardPAN(cardData);

	if (card_return == WRONG_PAN)
	{
		printf("\nDeclined, Please Enter PAN number between 16 and 19");
		return;
	}

	strcpy(transData->cardHolderData.primaryAccountNumber, cardData->primaryAccountNumber);

	printf("================= Card Data stored successfully ! ===================\n");

	terminal_return = getTransactionDate(termData);

	if (terminal_return == WRONG_DATE)
	{
		printf("\nDeclined, Please Enter the date in the correct format !");
		return;
	}

	strcpy(transData->terminalData.transactionDate, termData->transactionDate);

	printf("================ Transaction Date Stored Successfully ! ================= \n");

	terminal_return = isCardExpired(cardData, termData);

	if (terminal_return == EXPIRED_CARD)
	{
		printf("\nDeclined, Your Card is Expired !");
		return;
	}

	terminal_return = getTransactionAmount(termData);

	if (terminal_return == INVALID_AMOUNT)
	{
		printf("\nDeclined, Please Enter a positive amount !\n");
		return;
	}

	transData->terminalData.transAmount = termData->transAmount;

	terminal_return = setMaxAmount(termData);

	if (terminal_return == INVALID_MAX_AMOUNT)
	{
		printf("Declined, Please Enter Max Amount Above 0!\n");
	}

	transData->terminalData.maxTransAmount = termData->maxTransAmount;

	terminal_return = isBelowMaxAmount(termData);

	if (terminal_return == EXCEED_MAX_AMOUNT)
	{
		printf("\nPlease Enter your transaction amount below %0.2f\n", termData->maxTransAmount);
		return;
	}

	recieveTransactionData(transData);

	printf("\n================ Transaction Done Successfully ! =================\n");

	return;
							

}