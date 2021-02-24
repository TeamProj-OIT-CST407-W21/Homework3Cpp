
#include <iostream>
#include "LibRSA.h"


unsigned long long LibRSA::phiN()
{
	return ((p - 1) * (q - 1));
}
unsigned long long LibRSA::findN()
{
	return p * q;
}

void LibRSA::chooseP()
{
	p = arrP[pickIndex()];
}

void LibRSA::chooseQ()
{
	q = arrP[pickIndex()];
}

unsigned long long LibRSA::findD()
{
    unsigned long long d, exp1, exp3, mod1, mod3, totient1, totient3, q;
    //int iter;
    //move over as in video
    //uses extended Euclidean 
    bool flip_needed;
    exp1 = 1;
    exp3 = e; 
    mod1 = 0;
    mod3 = phiN();
    ///iter = 1;
    flip_needed = false;
    while (mod3 != 0)
    {
        q = exp3 / mod3;
        totient3 = exp3 % mod3;
        totient1 = exp1 + q * mod1;
        exp1 = mod1;
        mod1 = totient1;
        exp3 = mod3;
        mod3 = totient3;
        flip_needed = !(flip_needed); //flip conditional
    }
    if (exp3 != 1)
        return 0;
    if (flip_needed)
        d = phiN() - exp1;
    else
        d = exp1;
    return d;

}

//base = message, exponent = e or d and mod = N
unsigned long long LibRSA::changeMsg(unsigned long long base, unsigned long long exponent, unsigned long long mod)
{
    base %= mod;
    long long res = 1;
    while (exponent > 0) {
        if (exponent & 1) //in other words, if odd
            res = res * base % mod;
        base = base * base % mod;
        exponent >>= 1; //divide by 2
    }
    return res;

}

unsigned long long LibRSA::chooseMsg(unsigned long long m, char c)
{
    if (c == 'e')
        return changeMsg(m, e, findN());
    else if (c == 'd')
        return changeMsg(m, findD(), findN());
    else
        return (-1); //error case
}

/*unsigned long long LibRSA::chooseMsg(unsigned long long m, char c)
{
    if (c == 'e')
        return changeMsg(m, e, findN());
    else if (c == 'd')
        return changeMsg(m, findD(), findN());
    else
        return (-1); //error case
}*/

void LibRSA::chooseE() {
	e = arrE[pickIndex()];
}

int LibRSA::pickIndex()
{
	return std::rand() % 24;
}

