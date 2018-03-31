// Text_Compare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include "fetch_of_one_word.h"
using namespace std;

vector<float> Node;
std::vector<string> DataInput;

std::vector<std::string> tokenize(std::string in) {
	char sep = ' ';
	std::string::size_type b = 0;
	std::vector<std::string> result;

	while ((b = in.find_first_not_of(sep, b)) != std::string::npos) {
		auto e = in.find_first_of(sep, b);
		result.push_back(in.substr(b, e - b));
		b = e;
	}
	return result;
}

int main()
{
	fetch_of_one_word *FTCW = new fetch_of_one_word;
	string Storedword="Hello";
	string NewWord="Hello";

	//cout << FTCW->RateRecogWords(Storedword, NewWord);
	//https://github.com/nlohmann/json

	Storedword = "hello moatez amairi i'm fine";
	DataInput = tokenize(Storedword);


	for (int i = 0; i < DataInput.size(); i++) {
		cout << DataInput[i].c_str()<<endl ;
	}

	for (int i = 0; i < DataInput.size(); i++) {
		cout <<"recog rate of index number : "<<i <<" is " <<FTCW->RateRecogWords(DataInput[i], NewWord) <<endl ;
	}




	getchar();
    return 0;
}

