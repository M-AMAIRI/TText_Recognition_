#include "stdafx.h"
#include "fetch_of_one_word.h"
#include <iostream>
using namespace std;

fetch_of_one_word::fetch_of_one_word()
{
}

fetch_of_one_word::~fetch_of_one_word()
{
}

double fetch_of_one_word::RateRecogWords(string StoredWord, string DataIn)
{
	double rate_Length = 0;

	for (int i = 0; StoredWord[i] != 0; i++)
		if (StoredWord[i] <= 'z' && StoredWord[i] >= 'a')
			StoredWord[i] -= 32;



	for (int i = 0; DataIn[i] != 0; i++)
		if (DataIn[i] <= 'z' && DataIn[i] >= 'a')
			DataIn[i] -= 32;

	//---------------------------------------------------------------

	if (StoredWord.length() == DataIn.length())
	{
		rate_Length = 1;
	}
	

	double rate_Succ = 0;
	int occ = 0;

	int count;
	if (DataIn.length() <= DataIn.length())
	{
		count = DataIn.length();
	}
	else count = DataIn.length();
	for (int i = 0; i < count -1 ; i++)
	{
		if (checkPattern(StoredWord.c_str(), DataIn.substr(i, 2).c_str()) == true)
		{
			occ++;
		}
	}

	rate_Succ = (double)occ / (StoredWord.length()-1);

	if (occ == DataIn.length() - 1 && StoredWord.length() != DataIn.length())
	{
		rate_Length = 0.5;
	}

	//---------------------------------------------------------------

	int AllDataLength = DataIn.length();
	string existingSTR = DataIn.c_str();
	for (int j = 0; j < DataIn.length(); j++)
	{
		for (int i = 0; i < StoredWord.length(); i++)
		{
			if (DataIn[j] == StoredWord[i])
			{
				existingSTR[j]=' ';
			}
		}
	}

	int len = 0;
	for (int j = 0; j < existingSTR.length(); j++)
	{
		if (existingSTR[j] != ' ')
		{
			len++;
		}
	}


	double Integrite_Recog = (double)(existingSTR.length() - len) / (double)existingSTR.length();


	//cout << "Integrite_Recog : " << Integrite_Recog << endl;
	//cout << "rate_Length : " << rate_Length << endl;
	//cout << "rate_Succ : " << rate_Succ << endl;


	double res_recog_w = rate_Length*0.1 + rate_Succ*0.4 + Integrite_Recog*0.5 ;

	return res_recog_w;
}

// Function to check if characters in the input string 
// follows the same order as determined by characters 
// present in the given pattern // https://www.geeksforgeeks.org/check-string-follows-order-characters-defined-pattern-not/
bool fetch_of_one_word::checkPattern(string str, string pattern)
{
	// len stores length of the given pattern 
	char x = pattern[0];
	char y = pattern[1];
	for (int i = 0; i < str.length()-1; i++)
	{
		// x, y are two adjacent characters in pattern

		if (str[i] == x && str[i + 1] == y)
		{
			return true;
		}
		
	}

	// return true if string matches the pattern
	return false;
}

