// HW3Proj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LibRSA.h"
#include "RsaUI.h"

int main()
{
    LibRSA cipher;
    RsaUI consoleUI;
    bool keep_going = true;
    bool keep_keys = true;
    while (keep_going)
    {
        cipher.chooseP();
        cipher.chooseE();
        cipher.chooseQ();
        consoleUI.print_phiN(cipher.phiN());
        consoleUI.print_keyN(cipher.findN());
        consoleUI.print_keyE(cipher.getE());
        consoleUI.print_keyD(cipher.findD());
        while (keep_keys)
        {
            consoleUI.setChoice();
            consoleUI.setText();
            consoleUI.askKeys(cipher.getE(), cipher.findN(), cipher.findD());
            consoleUI.print_changedMsg(cipher.chooseMsg(consoleUI.getText(), consoleUI.getChoice()));
            keep_keys = consoleUI.keep_keys();
        }
        keep_keys = true;
        keep_going = consoleUI.contin();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
