// Homework3_ShippingCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>   //header used for outfile stream
#include <iomanip>   //used for setw, showpoint, setprecision
#include <ctype.h>   //used for isupper
#include <algorithm> //used for transform

using namespace std;

const double USA = 6.0;
const double CANADA = 8.0;
const double AUSTRALIA = 10.0;
const double MARS = 100.0;
const double FRAGILE_ITEM = 2.0;
const string OUTFILENAME = "Order.txt";   //filename


int main()
{
    ofstream fOutStream;               //declares file stream variable
    fOutStream.open(OUTFILENAME);      //opens the assiged outfile

    cout << left << setfill('.') << setw(50) << " " << endl;        //Using setfill and setw to fill in a set amount of space with '.' instead of hardcoding it.
    cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << setw(50) << " " << endl << endl << endl;

    fOutStream << left << setfill('.') << setw(50) << " " << endl;  //everything starting with fOutStream will be output to Order.txt
    fOutStream << "ITCS 2530 - Programming Assignment for week #3" << endl;
    fOutStream << setw(50) << " " << endl << endl << endl;

    double orderTotal = 0;
    char isItFragile = ' ';
    string itemName = " ";
    string destination = " ";

    cout << setw(49) << "Please enter the item name (no spaces)" << ':';
    fOutStream << setw(49) << "Please enter the item name (no spaces)" << ':';

    cin >> itemName;
    fOutStream << itemName << endl;
    transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper); //changes user input to capital letters
    
    cout << setw(49) << "Is the item fragile? (y=yes/n=no)" << ':';
    fOutStream << setw(49) << "Is the item fragile? (y=yes/n=no)" << ':';

    cin >> isItFragile;
    fOutStream << isItFragile << endl;

    isItFragile = toupper(isItFragile); //changes user input to capital letter
    if (!(isItFragile == 'Y' || isItFragile == 'N')) //if the input is neither Y or N, cout invalid entry and end program
    {
        cout << endl << "Invalid entry, exiting" << endl;
        fOutStream << endl << "Invalid entry, exiting" << endl;
        system("pause");
        return 1;
    }
    
    cout << setw(49) << "Please enter your order total" << ':';
    fOutStream << setw(49) << "Please enter your order total" << ':';

    cin >> orderTotal;
    fOutStream << orderTotal << endl;


    cout << setw(49) << "Please enter destination. (usa/can/aus/mars)" << ':';
    fOutStream << setw(49) << "Please enter destination. (usa/can/aus/mars)" << ':';

    cin >> destination;
    fOutStream << destination << endl;

    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

    cout << endl;
    fOutStream << endl;

    if (!(destination == "USA" || destination == "CAN" || destination == "AUS" || destination == "MARS")) //if the input is neitherUSA, CAN, OR AUS, cout invalid entry and end program
    {
        cout << endl << "Invalid entry, exiting" << endl;
        fOutStream << endl << "Invalid entry, exiting" << endl;
        system("pause");
        return 2;
    }

    cout << fixed << showpoint << setprecision(2);  //Sets the following decimal numbers to a fixed notation and shows the trailing zero's
                                                    //Setting precision to two will shorten the decimal places to two. 

    double shippingCost = 0;
    
    if (orderTotal < 50)
    {
        if (destination == "USA")
            shippingCost = USA;
        else if (destination == "CAN")
            shippingCost = CANADA;
        else if (destination == "AUS")
            shippingCost = AUSTRALIA;
        else if (destination == "MARS")
            shippingCost = MARS;
        else
        {
            cout << "Something went wrong, sorry!" << endl;  //included a catch all just in case
            fOutStream << "Something went wrong, sorry!" << endl;
        }
    }
    else if (orderTotal >= 50.01 && orderTotal <= 100)
    {
        if (destination == "USA")
            shippingCost = USA + 3;
        else if (destination == "CAN")
            shippingCost = CANADA + 4;
        else if (destination == "AUS")
            shippingCost = AUSTRALIA+ 4;
        else if (destination == "MARS")
            shippingCost = MARS + 10;
        else
        {
            cout << "Something went wrong, sorry!" << endl;  
            fOutStream << "Something went wrong, sorry!" << endl;
        }
    }
    else if (orderTotal >= 100.01 && orderTotal <= 150)
    {
        if (destination == "USA")
            shippingCost = USA + 6;
        else if (destination == "CAN")
            shippingCost = CANADA + 7;
        else if (destination == "AUS")
            shippingCost = AUSTRALIA + 7;
        else if (destination == "MARS")
            shippingCost = MARS + 20;
        else
        {
            cout << "Something went wrong, sorry!" << endl;  
            fOutStream << "Something went wrong, sorry!" << endl;
        }
    }
    else
    {
        cout << "Something went wrong, sorry!" << endl;  //included a catch all just in case
        fOutStream << "Something went wrong, sorry!" << endl;
    }

    if (isItFragile == 'Y')             //add FRAGILE_ITEM to order total if input was Y
        shippingCost = shippingCost + FRAGILE_ITEM;

    cout << setw(43) << "Your item is" << itemName << endl;
    cout << setw(43) << "Your shipping cost is" << '$' << shippingCost << endl;
    cout << setw(43) << "You are shipping to" << destination << endl;
    cout << setw(43) << "Your total shipping costs are" << '$' << shippingCost + orderTotal << endl << endl;

    cout << right << setfill('-') << setw(53) << "Thank You!" <<  endl << endl;

    fOutStream << setw(43) << "Your item is" << itemName << endl;
    fOutStream << setw(43) << "Your shipping cost is" << '$' << shippingCost << endl;
    fOutStream << setw(43) << "You are shipping to" << destination << endl;
    fOutStream << setw(43) << "Your total shipping costs are" << '$' << shippingCost + orderTotal << endl << endl;

    fOutStream << right << setfill('-') << setw(53) << "Thank You!" << endl << endl;

    fOutStream.close();           //closes the outfile

    system("pause");
    return 0;
}
