#include "../../Utilities/Registers.h"
#include "../../Utilities/Typedefs.h"
#include "../../Utilities/Common_Macros.h"
#include "DIO.h"

/**
 * \brief  DIO_Pin_Write : Making a certain pin LOW or HIGH
 *
 * \param  u8Pin_number (Input) : The Micro-controller pin number (A0 ... D7)
 * \param  u8Value (Input) : LOW or HIGH (Macros) (If other values except for HIGH or LOW is entered the function does nothing)
 * \return u8 : The return of this function will be an indication of the execution
 *
 **/
Error DIO_Pin_Write(u8 u8Pin_number , u8 u8Value)
{
	if (u8Pin_number >= 0 && u8Pin_number <= 7)
	{
		if (u8Value == HIGH)
		{
			SET_BIT(PORTA, u8Pin_number);
			return NO_ERROR;
		}
		else if (u8Value == LOW)
		{
			RESET_BIT(PORTA, u8Pin_number);
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Pin_number >= 8 && u8Pin_number <= 15)
	{
		u8Pin_number -= 8;
		if (u8Value == HIGH)
		{
			SET_BIT(PORTB, u8Pin_number);
			return NO_ERROR;
		}
		else if (u8Value == LOW)
		{
			RESET_BIT(PORTB, u8Pin_number);
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Pin_number >= 16 && u8Pin_number <= 23)
	{
		u8Pin_number -= 16;
		if (u8Value == HIGH)
		{
			SET_BIT(PORTC, u8Pin_number);
			return NO_ERROR;
		}
		else if (u8Value == LOW)
		{
			RESET_BIT(PORTC, u8Pin_number);
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}

	}
	else if (u8Pin_number >= 24 && u8Pin_number <= 31)
	{
		u8Pin_number -= 24;
		if (u8Value == HIGH)
		{
			SET_BIT(PORTD, u8Pin_number);
			return NO_ERROR;
		}
		else if (u8Value == LOW)
		{
			RESET_BIT(PORTD, u8Pin_number);
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}

	}
}


/**
 * \brief  DIO_Pin_Read : Reading a certain pin if it's LOW or HIGH and put the value in the passed address
 *
 * \param  u8Pin_number (Input) : The micro controller pin number (A0 ... D7)
 * \param  *pu8Reading (OUTPUT) : The pin state will be stored in the space that this pointer points to
 * \return u8 : The return of this function will be an indication of the execution
 *
 **/
Error DIO_Pin_Read(u8 u8Pin_number , u8 *pu8Reading)
{
	if (u8Pin_number >= 0 && u8Pin_number <= 7)
	{
		*pu8Reading = READ_BIT(PORTA, u8Pin_number);
		return NO_ERROR;
	}
	else if (u8Pin_number >= 8 && u8Pin_number <= 15)
	{
		u8Pin_number -= 8;
		*pu8Reading = READ_BIT(PORTB, u8Pin_number);
		return NO_ERROR;
	}
	else if (u8Pin_number >= 16 && u8Pin_number <= 23)
	{
		u8Pin_number -= 16;
		*pu8Reading = READ_BIT(PORTC, u8Pin_number);
		return NO_ERROR;
	}
	else if (u8Pin_number >= 24 && u8Pin_number <= 31)
	{
		u8Pin_number -= 24;
		*pu8Reading = READ_BIT(PORTD, u8Pin_number);
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}


/**
 * \brief DIO_Pin_Init : Making a certain pin Input or OUTPUT
 *
 * \param u8Pin_number (Input) : The micro controller pin number (A0 ... D7)
 * \param u8State (Input) : Determine the state of the chosen pin whether it's INPUT or OUTPUT (macros)
 * \return u8 : The return of this function will be an indication of the execution
 *
 **/
Error DIO_Pin_Init(u8 u8Pin_number , u8 u8State)
{
	if (u8Pin_number >= 0 && u8Pin_number <= 7)
		{
		if (u8State == OUTPUT)
		{
			SET_BIT(DDRA, u8Pin_number);
			return NO_ERROR;
		}
		else if (u8State == INPUT)
		{
			RESET_BIT(DDRA, u8Pin_number);
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Pin_number >= 8 && u8Pin_number <= 15)
	{
		u8Pin_number -= 8;
		if (u8State == OUTPUT)
		{
			SET_BIT(DDRB, u8Pin_number);
			return NO_ERROR;
		}
		else if (u8State == INPUT)
		{
			RESET_BIT(DDRB, u8Pin_number);
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Pin_number >= 16 && u8Pin_number <= 23)
	{
		u8Pin_number -= 16;
		if (u8State == OUTPUT)
		{
			SET_BIT(DDRC, u8Pin_number);
			return NO_ERROR;
		}
		else if (u8State == INPUT)
		{
			RESET_BIT(DDRC, u8Pin_number);
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Pin_number >= 24 && u8Pin_number <= 31)
	{
		u8Pin_number -= 24;
		if (u8State == OUTPUT)
		{
			SET_BIT(DDRD, u8Pin_number);
			return NO_ERROR;
		}
		else if (u8State == INPUT)
		{
			RESET_BIT(DDRD, u8Pin_number);
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
}


/**
 * \brief  DIO_Port_Write : Making a certain port LOW or HIGH
 *
 * \param  u8Port_index (Input) : The micro controller port number (A , B , C , D)
 * \param  u8Value (Input) : Writes a certain value to the port
 * \return u8 : The return of this function will be an indication of the execution
 *
 **/
Error DIO_Port_Write(u8 u8Port_index , u8 u8Value)
{
	if (u8Port_index == PORTA)
	{
		if (u8Value == HIGH)
		{
			PORTA = 0xFF;
			return NO_ERROR;
		}
		else if (u8Value == LOW)
		{
			PORTA = 0x00;
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Port_index == PORTB)
	{
		if (u8Value == HIGH)
		{
			PORTB = 0xFF;
			return NO_ERROR;
		}
		else if (u8Value == LOW)
		{
			PORTB = 0x00;
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Port_index == PORTC)
	{
		if (u8Value == HIGH)
		{
			PORTC = 0xFF;
			return NO_ERROR;
		}
		else if (u8Value == LOW)
		{
			PORTC = 0x00;
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Port_index == PORTD)
	{
		if (u8Value == HIGH)
		{
			PORTD = 0xFF;
			return NO_ERROR;
		}
		else if (u8Value == LOW)
		{
			PORTD = 0x00;
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}


/**
 * \brief  DIO_Port_Read : Reads the value of a chosen port
 *
 * \param  u8Port_index (Input) : The micro controller port number (A , B , C , D)
 * \param  *pu8Reading (Output) : The port value will bes stored in it
 * \return u8 : The return of this function will be an indication of the execution
 *
 **/
Error DIO_Port_Read(u8 u8Port_index , u8 *pu8Reading)  // Think about this again !!!
{
	if (u8Port_index == PORTA)
	{
		*pu8Reading = PINA;
		return NO_ERROR;
	}
	else if (u8Port_index == PORTB)
	{
		*pu8Reading = PINB;
		return NO_ERROR;
	}
	else if (u8Port_index == PORTC)
	{
		*pu8Reading = PINC;
		return NO_ERROR;
	}
	else if (u8Port_index == PORTD)
	{
		*pu8Reading = PIND;
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}


/**
 * \brief  DIO_Port_Direction : Makes the port input or output
 *
 * \param  u8Port_index (Input) : The micro controller port number (A , B , C , D)
 * \param  u8State (Input) : Chosen state INPUT or OUTPUT (macros)
 * \return u8 : The return of this function will be an indication of the execution
 *
 **/
Error DIO_Port_Direction(u8 u8Port_index , u8 u8State)
{
	if (u8Port_index == PORTA)
	{
		if (u8State == OUTPUT)
		{
			DDRA = 0xFF;
			return NO_ERROR;
		}
		else if (u8State == INPUT)
		{
			DDRA = 0x00;
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Port_index == PORTB)
	{
		if (u8State == OUTPUT)
		{
			DDRB = 0xFF;
			return NO_ERROR;
		}
		else if (u8State == INPUT)
		{
			DDRB = 0x00;
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Port_index == PORTC)
	{
		if (u8State == OUTPUT)
		{
			DDRC = 0xFF;
			return NO_ERROR;
		}
		else if (u8State == INPUT)
		{
			DDRC = 0x00;
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else if (u8Port_index == PORTD)
	{
		if (u8State == OUTPUT)
		{
			DDRD = 0xFF;
			return NO_ERROR;
		}
		else if (u8State == INPUT)
		{
			DDRD = 0x00;
			return NO_ERROR;
		}
		else
		{
			return ERROR;
		}
	}
	else
	{
		return ERROR;
	}
}


/**
 * \brief DIO_Pin_Toggle : A function that toggle a particular pin ( It has to be output )
 *
 * \param u8Pin_index : The micro controller pin number (A0 ... D7)
 * \return u8 : The return of this function will be an indication of the execution
 *
 **/
Error DIO_Pin_Toggle(u8 u8Pin_number)
{
	if (u8Pin_number >= 0 && u8Pin_number <= 7)
	{
		TOGGLE_BIT(PORTA, u8Pin_number);
		return NO_ERROR;
	}
	else if (u8Pin_number >= 8 && u8Pin_number <= 15)
	{
		u8Pin_number -= 8;
		TOGGLE_BIT(PORTB, u8Pin_number);
		return NO_ERROR;
	}
	else if (u8Pin_number >= 16 && u8Pin_number <= 23)
	{
		u8Pin_number -= 16;
		TOGGLE_BIT(PORTC, u8Pin_number);
		return NO_ERROR;
	}
	else if (u8Pin_number >= 24 && u8Pin_number <= 31)
	{
		u8Pin_number -= 24;
		TOGGLE_BIT(PORTD, u8Pin_number);
		return NO_ERROR;

	}
	else
	{
		return ERROR;
	}
}

