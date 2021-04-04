// SwitchStatements.cpp : This file contains the 'main' function. Program execution begins and ends there.

//A switch structure is an alternative to the if-else statement. Good for simple evaluations. int's or chars.

#include <iostream>

using namespace std;

int main()
{
    int vowels_a = 0;
    int vowels_e = 0;
    int vowels_i = 0;
    int vowels_o = 0;
    int vowels_u = 0;

    char c = ' ';
    cin >> c;

    switch (c)
    {
    case 'a':           //if case is 'a'
        vowels_a++;     //add 1 to vowel a
        break;
    case 'e':
        vowels_e++;
        break;
    case 'i':
    case 'I':         //you can also do multiple cases together
        vowels_i++;
        break;
    case 'o':
        vowels_o++;
        break;
    case 'u':
        vowels_u++;
        break;

    default:   //default will execute when the input isnt acceptable for anything above, a catch all. Its not neccesary to include but helpful. ex. 'z' 
        cout << "invalid entry" << endl;
        break;
    }

    system("pause");
    return 0;
}
