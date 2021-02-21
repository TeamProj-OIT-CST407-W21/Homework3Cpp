#pragma once

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

#ifndef RSAUI_H
#define RSAUI_H
class RsaUI
{
public:
	RsaUI();
	~RsaUI();
	char getChoice();
	void setChoice();
	uint64_t getExponent();
	void setExponent();
	uint64_t getN();
	void setN();
	uint64_t getPlainText();
	void setPlainText();
	uint64_t getCipherText();
	void setCipherText();

private:
	char choice;
	uint64_t exponent;
	uint64_t n;
	uint64_t plaintext;
	uint64_t ciphertext;
};
#endif
//change to include libRSA