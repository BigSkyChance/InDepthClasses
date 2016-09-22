#include <iostream>
#include <string.h>
#include "Class.h"
#pragma warning (disable:4996)

String::String ()
{
	NumChars	 = 0;
	NumSlots	 = NumChars;
	pChar		 = new char[NumSlots + 1];
	pChar		 = '\0';
}

String::String(const String & Str)
{
	NumChars = Str.NumChars;
	NumSlots = NumChars;
	pChar = new char[NumSlots + 1];
	strcpy(pChar, Str.pChar);
}

String::String(const char Str[])
{
	NumChars		= strlen(Str);
	NumSlots		= NumChars;
	pChar			= new char[NumSlots + 1];
	strcpy			(pChar, Str);
}

String::~String()
{
	delete [] pChar;
}

void String::Copy(const String & Str)
{
	if (this != &Str)
	{
		if (NumSlots < Str.NumChars)
			{
				delete[] pChar;
				NumSlots = Str.NumChars;
				pChar = new char[NumSlots + 1];
			}
		else;
		NumChars = Str.NumChars;
		strcpy(pChar, Str.pChar);
	}
}

void String::Copy(const char Str[])
{
	if (strcmp(pChar, Str) != 0)
	{
			if (NumSlots < strlen(Str))
			{
				delete[] pChar;
				NumSlots = strlen(Str);
				pChar = new char[NumSlots + 1];
			}
			else;
		NumChars = strlen(Str);
		strcpy(pChar, Str);
	}
}

void String::Concat(const String & Str)
{
	char * pTemp;
	
	NumSlots = NumChars + Str.NumChars;
	pTemp = new char[NumSlots + 1];
	strcpy(pTemp, pChar);
	strcat(pTemp, Str.pChar);
	delete[] pChar;
	pChar = pTemp;
	NumChars = NumSlots;
}

void String::Concat(const char Str[])
{
	char * pTemp;

	NumSlots = NumChars + strlen(Str);
	pTemp = new char[NumSlots + 1];
	strcpy(pTemp, pChar);
	strcat(pTemp, Str);
	delete[] pChar;
	pChar = pTemp;
	NumChars = NumSlots;
}

int String::Len()
{
	return NumChars;
}

String & String::operator=(const String & Str)
{
	Copy(Str);
	return *this;
}

String & String::operator=(const char Str [])
{
	Copy(Str);
	return *this;
}

bool String::operator==(const String & Str) const
{
	if (Compare(Str) == 0)
		return true;
	else
		return false;
}

bool String::operator<(const String & Str) const
{
	if (Compare(Str) == 1)
		return true;
	else
		return false;
}

bool String::operator<=(const String & Str) const
{
	if (Compare(Str) == 1 || Compare(Str) == 0)
		return true;
	else
		return false;
}

bool String::operator!=(const String & Str) const
{
	if (Compare(Str) != 0)
		return true;
	else
		return false;
}

bool String::operator>=(const String & Str) const
{
	if (Compare(Str) == -1 || Compare(Str) == 0)
		return true;
	else
		return false;
}

bool String::operator>(const String & Str) const
{
	if (Compare(Str) == -1)
		return true;
	else
		return false;
}

bool String::operator==(const char Str []) const
{
	if (Compare(Str) == 0)
		return true;
	else
		return false;
}

bool String::operator<(const char Str []) const
{
	if (Compare(Str) == 1)
		return true;
	else
		return false;
}

bool String::operator<=(const char Str []) const
{
	if (Compare(Str) == 1 || Compare(Str) == 0)
		return true;
	else
		return false;
}

bool String::operator!=(const char Str []) const
{
	if (Compare(Str) == 0)
		return false;
	else
		return true;
}

bool String::operator>=(const char Str[]) const
{
	if (Compare(Str) == -1 || Compare(Str) == 0)
		return true;
	else
		return false;
}

bool String::operator>(const char Str []) const
{
	if (Compare(Str) == -1)
		return true;
	else
		return false;
}

String & String::operator+=(const String & Str)
{
	Concat(Str);
	return *this;
}

String & String::operator+=(const char Str[])
{
	Concat(Str);
	return *this;
}

String String::operator+(const String & Str)
{
	String	Temp(*this);
	Temp.Concat(Str);
	return Temp;
}

String String::operator+(const char Str []) const
{
	String Temp(*this);
	Temp.Concat(Str);
	return Temp;
}

int String::Compare(const char Str []) const
{
	if (strcmp(pChar, Str) == -1)
		return -1;
	else if (strcmp(pChar, Str) == 0)
		return 0;
	else
		return 1;
}

int String::Compare(const String & Str) const
{
	if (strcmp(pChar, Str.pChar) == -1)
		return -1;
	else if (strcmp(pChar, Str.pChar) == 0)
		return 0;
	else
		return 1;
}

istream & String::Read(istream & in)
{
	const	int		SizeGuess(50);
	char *	Temp;
	char	c;

	NumChars = 0;
	while ((c = in.get()) != '\n')
	{
		pChar[NumChars++] = c;
		if (NumChars >= NumSlots)
		{
			NumSlots += SizeGuess;
			Temp = new char[NumSlots + 1];
			memcpy(Temp, pChar, NumChars);
			delete[] pChar;
			pChar = Temp;
		}
		else;
	}
	pChar[NumChars] = '\0';
	return in;
}
