#pragma once

#include <iostream>
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
	unsigned long long getExponent();
	void setExponent();
	unsigned long long getN();
	void setN();
	unsigned long long getPlainText();
	void setPlainText();
	unsigned long long getCipherText();
	void setCipherText();

private:
	char choice;
	unsigned long long exponent;
	unsigned long long n;
	unsigned long long plaintext;
	unsigned long long ciphertext;
};
#endif
//change to include libRSA
