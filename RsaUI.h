#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class RsaUI
{
public:
	RsaUI();
	~RsaUI();
	const char getChoice();
	void setChoice();
	const unsigned long long getExponent();
	void setExponent();
	//unsigned long long getN();
	//void setN();
	const unsigned long long getText();
	void setText();


	bool contin();
	bool keep_keys();

	const void print_phiN(unsigned long long phi);
	const void print_keyE(unsigned long long e);
	const void print_keyD(unsigned long long d);
	const void print_keyN(unsigned long long n);
	const void print_changedMsg(unsigned long long msg);

	const void askKeys(unsigned long long e, unsigned long long n, unsigned long long d);

private:
	char choice;
	unsigned long long exponent;
	unsigned long long n;
	unsigned long long text;
};
