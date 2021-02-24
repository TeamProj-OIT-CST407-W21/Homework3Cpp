#pragma once

class LibRSA
{
private:

	unsigned long long e;
	unsigned long long p;
	unsigned long long q;
	//unsigned long long d;
	unsigned long long arrQ[25]{ 63527, 51829, 43753, 11731, 12457,
		14747, 15661, 17333, 19477, 21017,
		21019, 22777, 23081, 24197, 25583,
		26113, 27689, 30977, 31121, 29209,
		31751, 33013, 35407, 36209, 40459
	};

	unsigned long long arrP[25] { 11689, 13099, 13759, 15031, 16901, 
		17623, 18701, 21683, 21871, 22079, 
		23537, 24979, 25523, 25219, 26959, 
		27691, 30047, 30577, 31189, 29209, 
		29389, 32401, 32611, 34061, 35527
	};

	unsigned long long arrE[25]{ 65839, 67181, 69247, 70393, 70571,
		71597, 71879, 71707, 73859, 73417,
		74201, 75797, 76079, 76441, 77983,
		77999, 78167, 78283, 81569, 82729,
		83257, 84947, 85087, 87403, 90511
	};

	int pickIndex();
	unsigned long long changeMsg(unsigned long long base, unsigned long long exponent, unsigned long long mod); //encrypt or decrypt

public:
	LibRSA() : e(0),p(0),q(0) {
	};

	const unsigned long long getE() { return e; }
	void chooseP();
	void chooseQ();
	void chooseE();

	unsigned long long phiN();
	unsigned long long findN();
	unsigned long long findD();
	unsigned long long chooseMsg(unsigned long long m, char c);
};

