#include "RsaUI.h"

RsaUI::RsaUI()
{
	choice = '\0';
	exponent = 0;
	n = 0;
	plaintext = 0;
	ciphertext = 0;
}

RsaUI::~RsaUI()
{
	choice = '\0';
	exponent = 0;
	n = 0;
	plaintext = 0;
	ciphertext = 0;
}

char RsaUI::getChoice()
{
	return choice;
}

void RsaUI::setChoice()
{
	cout << "Encrypt or Decrypt(e/d): " << endl;
	cin >> choice;
	while (choice != 'e' && choice != 'd')
	{
		cout << "Improper input, try again: " << endl;
		cin >> choice;
	}
	choice = tolower(choice);
}

unsigned long long RsaUI::getExponent()
{
	return exponent;
}

void RsaUI::setExponent()
{
	cout << "Enter key " << choice << ": " << endl;
	cin >> exponent;
}

unsigned long long RsaUI::getN()
{
	return n;
}

void RsaUI::setN()
{
	cout << "Enter key N: " << endl;
	cin >> n;
}

unsigned long long RsaUI::getPlainText()
{
	return plaintext;
}

void RsaUI::setPlainText()
{
	cout << "Enter a number for plaintext: " << endl;
	cin >> plaintext;
}

unsigned long long RsaUI::getCipherText()
{
	return ciphertext;
}

void RsaUI::setCipherText()
{
	cout << "Enter a number for ciphertext: " << endl;
	cin >> ciphertext;
}
