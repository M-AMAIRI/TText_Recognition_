#pragma once
#include <iostream>
using namespace std;
class fetch_of_one_word
{
public:
	fetch_of_one_word();
	~fetch_of_one_word();
	double RateRecogWords(string ch1, string ch2);
	bool checkPattern(string str, string pattern);

};

