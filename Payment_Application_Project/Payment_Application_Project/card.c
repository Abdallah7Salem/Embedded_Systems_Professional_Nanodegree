#include "card.h"
#include <stdio.h>
#include <string.h>

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("Please Enter your name in 20 to 24 characters: ");
	gets(cardData->cardHolderName);

	if ((strlen(cardData->cardHolderName) == 0) || (strlen(cardData->cardHolderName) < 20) || (strlen(cardData->cardHolderName) > 24))
	{
		return WRONG_NAME;
	}
	
	return CARD_OK;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	printf("Please Enter your card expiry date in the format MM/YY: ");
	gets(cardData->cardExpirationDate);

	if ((strlen(cardData->cardExpirationDate) == 0) || (strlen(cardData->cardExpirationDate) != 5) || (cardData->cardExpirationDate[2] != '/'))
	{
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[0] < '0' || cardData->cardExpirationDate[0] > '9')
	{
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[1] < '0' || cardData->cardExpirationDate[1] > '9')
	{
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[3] < '0' || cardData->cardExpirationDate[3] > '9')
	{
		return WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[4] < '0' || cardData->cardExpirationDate[4] > '9')
	{
		return WRONG_EXP_DATE;
	}
	return CARD_OK;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("Please enter your card's primary account number from 16 to 19 numbers: ");
	gets(cardData->primaryAccountNumber);

	if ((strlen(cardData->primaryAccountNumber) == 0) || (strlen(cardData->primaryAccountNumber) < 16) || (strlen(cardData->primaryAccountNumber) > 19))
	{
		return WRONG_PAN;
	}

	return CARD_OK;
}
