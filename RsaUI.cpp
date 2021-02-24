#include <ctype.h>
#include "RsaUI.h"

RsaUI::RsaUI()
{
	choice = '\0';
	exponent = 0;
	n = 0;
	text = 0;
	//ciphertext = 0;
}

RsaUI::~RsaUI()
{
	choice = '\0';
	exponent = 0;
	n = 0;
	text = 0;
	//ciphertext = 0;
}

const char RsaUI::getChoice()
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

bool RsaUI::contin()
{
	char continu;
	std::cout << "Press 'y' to continue, otherwise press any key to exit" << std::endl;
	std::cin >> continu;
	continu = tolower(continu);
	if (continu == 'y')
		return true;
	else
		return false;
}

bool RsaUI::keep_keys()
{
	char continu;
	std::cout << "Press 'y' to keep your keys or any other character to change keys" << std::endl;
	std::cin >> continu;
	continu = tolower(continu);
	if (continu == 'y')
		return true;
	else
		return false;
}

const unsigned long long RsaUI::getExponent()
{
	return exponent;
}

void RsaUI::setExponent()
{
	cout << "Enter key " << choice << ": " << endl;
	cin >> exponent;
}

/*unsigned long long RsaUI::getN()
{
	return n;
}*/

/*void RsaUI::setN()
{
	cout << "Enter key N: " << endl;
	cin >> n;
}*/


const void RsaUI::askKeys(unsigned long long e, unsigned long long n, unsigned long long d)
{
	unsigned long long E;
	unsigned long long D;
	unsigned long long N;
	bool wrong = true;
	while (getChoice() == 'e' && wrong)
	{
		std::cout << "Enter E:\n" << std::endl;
		std::cin >> E;
		if (E != e)
		{
			std::cout << "ERROR: Wrong Input!\n";
		}
		else
		{
			wrong = false;
		}
	}
	wrong = true;
	while (getChoice() == 'd' && wrong)
	{
		std::cout << "Enter D:\n" << std::endl;
		std::cin >> D;
		if (D != d)
		{
			std::cout << "ERROR: Wrong Input!\n";
		}
		else
		{
			wrong = false;
		}
	}
	wrong = true;
	while (wrong)
	{
		std::cout << "Enter N:\n" << std::endl;
		std::cin >> N;
		if (N != n)
		{
			std::cout << "ERROR: Wrong Input!\n";
		}
		else
		{
			wrong = false;
		}
	}
}

const unsigned long long RsaUI::getText()
{
	return text;
}

void RsaUI::setText()
{
	cout << "Enter a number for your message: " << endl;
	cin >> text;
}

const void RsaUI::print_phiN(unsigned long long phi)
{
	std::cout << "Your phi(N) is:\n" << phi << std::endl;
}
const void RsaUI::print_keyE(unsigned long long e)
{
	std::cout << "Your E (public exponent encryption key) is:\n" << e << std::endl;
}
const void RsaUI::print_keyD(unsigned long long d)
{
	std::cout << "Your D (private decryption key) is:\n" << d << std::endl;
}
const void RsaUI::print_keyN(unsigned long long n)
{
	std::cout << "Your N (public mod key) is:\n" << n << std::endl;
}
const void RsaUI::print_changedMsg(unsigned long long msg)
{
	std::cout << "Your New Message is:\n" << msg << std::endl;
}