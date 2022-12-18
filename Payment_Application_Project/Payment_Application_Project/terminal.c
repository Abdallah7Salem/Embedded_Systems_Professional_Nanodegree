#include "terminal.h"
#include <string.h>
#include <stdio.h>

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("Please enter the transaction date in the form of DD/MM/YYYY: ");
	gets(termData->transactionDate);

	if ((strlen(termData->transactionDate) == 0) || (strlen(termData->transactionDate) < 10) || (termData->transactionDate[2] != '/') || (termData->transactionDate[5] != '/'))
	{
		return WRONG_DATE;
	}
	else if (termData->transactionDate[3] > '1')
	{
		return WRONG_DATE;
	}
	else if ((termData->transactionDate[3] == '1') && (termData->transactionDate[4] > '2'))
	{
		return WRONG_DATE;
	}
	else if (termData->transactionDate[0] < '0' || termData->transactionDate[0] > '9')
	{
		return WRONG_DATE;
	}
	else if (termData->transactionDate[1] < '0' || termData->transactionDate[1] > '9')
	{
		return WRONG_DATE;
	}
	else if (termData->transactionDate[3] < '0' || termData->transactionDate[3] > '9')
	{
		return WRONG_DATE;
	}
	else if (termData->transactionDate[4] < '0' || termData->transactionDate[4] > '9')
	{
		return WRONG_DATE;
	}
	else if (termData->transactionDate[6] < '0' || termData->transactionDate[6] > '9')
	{
		return WRONG_DATE;
	}
	else if (termData->transactionDate[7] < '0' || termData->transactionDate[7] > '9')
	{
		return WRONG_DATE;
	}
	else if (termData->transactionDate[8] < '0' || termData->transactionDate[8] > '9')
	{
		return WRONG_DATE;
	}
	else if (termData->transactionDate[9] < '0' || termData->transactionDate[9] > '9')
	{
		return WRONG_DATE;
	}
	
	return TERMINAL_OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
	// The Card expiry date is entered in the form : MM/YY --> [01] 2 [34]
	// The transaction date is entered in the form : DD/MM/YYYY --> 012 [34] 567   [89]

	if (atoi("cardData->cardExpirationDate[3]") < atoi("termData->transactionDate[8]"))
	{
		return EXPIRED_CARD;
	}
	else if ((cardData->cardExpirationDate[3] == termData->transactionDate[8]) && (cardData->cardExpirationDate[4] < termData->transactionDate[9]))
	{
		return EXPIRED_CARD;
	}
	else if (cardData->cardExpirationDate[0] < termData->transactionDate[3])
	{
		return EXPIRED_CARD;
	}
	else if ((cardData->cardExpirationDate[0] == termData->transactionDate[3]) && (cardData->cardExpirationDate[1] < termData->transactionDate[4]))
	{
		return EXPIRED_CARD;
	}
	
	return TERMINAL_OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("Please enter your transaction amount: ");
	scanf_s("%f", &termData->transAmount);

	if (termData->transAmount <= 0)
	{
		return INVALID_AMOUNT;
	}
	
	return TERMINAL_OK;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		return EXCEED_MAX_AMOUNT;
	}

	return TERMINAL_OK;
	
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	printf("Please enter the max transaction amount: ");
	scanf_s("%f", &termData->maxTransAmount);
	if ((termData->maxTransAmount <= 0))
	{
		return INVALID_MAX_AMOUNT;
	}
	
	return TERMINAL_OK;

}

