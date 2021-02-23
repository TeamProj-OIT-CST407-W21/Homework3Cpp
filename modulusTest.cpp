// modulusTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RsaUI.cpp"

uint64_t FindD(uint64_t exp, uint64_t mod);

int main()
{
    //int base = 2, exponent = 113971301, modulus = 210506400;


	/// <summary>
	/// Performs Encryption/decryption
	/// </summary>
	/// <returns> uint64_t </returns>
    
	/*int result = 1;
	for (int i = 0; i < exponent; i++)
		result = (result * base) % modulus;

	std::cout << "(2^113971301)\% 210506400 = " << result << std::endl;


    uint64_t d = FindD(exponent, modulus);
    std::cout << "D is: " << d << std::endl;*/

    char cont = 'y';

    while (cont == 'y')
    {
        RsaUI ui;
        //Generate new RSA class, and key sets
        //Call RsaUI functions setChoice, setExponent, setN, and relevant setText function
            //in order to pass the values to the UI class
        //Run program's encryption/decryption, based off of user choice

        if (ui.getChoice() == 'e')
            //do encryption
            //make sure to set the ciphertext in RsaUI after it is encrypted
            std::cout << "Your cipher text is: " << ui.getCipherText() << std::endl;
        else
        {
            //do decryption
            //make sure to set the plaintext in RsaUI after it is decrypted
            std::cout << "Your plaintext is: " << ui.getPlainText() << std::endl;
        }    

        std::cout << "Would you like to run the program again(y/n)? " << std::endl;
        std::cin >> cont;
        cont = tolower(cont);
        while (cont != 'y' && cont != 'n')
        {
            std::cout << "Improper input, please input either 'y' or 'n' (without quotations): " << std::endl;
            std::cin >> cont;
            cont = tolower(cont);
        }
    }

    return 0;
}

uint64_t FindD(uint64_t exp, uint64_t mod)
{
    uint64_t d, exp1, exp3, mod1, mod3, totient1, totient3, q;
    int64_t iter;
    exp1 = 1;
    exp3 = exp;
    mod1 = 0;
    mod3 = mod;
    iter = 1;
    while (mod3 != 0)
    {
        q = exp3 / mod3;
        totient3 = exp3 % mod3;
        totient1 = exp1 + q * mod1;
        exp1 = mod1;
        mod1 = totient1;
        exp3 = mod3;
        mod3 = totient3;
        iter = -iter;
    }
    if (exp3 != 1)
        return  0;
    if (iter < 0)
        d = mod - exp1;
    else
        d = exp1;
    return d;
}
