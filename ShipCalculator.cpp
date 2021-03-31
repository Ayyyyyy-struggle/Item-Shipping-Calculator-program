/*
Item shipping calculate program
Four destination: USA, Canada, Austrilia, Jupiter
Four shipping fee charge range: =< $50, $50-$100, $100.1-$150, >$150
Fragile item charge extra $2.00
*/



#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <fstream>
using namespace std;

// Create an output file
const string OUTORDER = "Oder.text";

// Declare constants - ship cost range indicators $50.00, $100.00, $150.00
const double range1 = 50.00;
const double range2 = 100.00;
const double range3 = 150;

// Declare constants - shipping cost to UAS
const double range1_usa = 6.00;
const double range2_usa = 9.00;
const double raneg3_usa = 12.00;
const double range4_usa = 0.00;

// Declare constants - shipping to Canada
const double range1_can = 8.00;
const double range2_can = 12.00;
const double range3_can = 15.00;
const double range4_can = 0.00;

// Declare constants - shipping to Austrilia
const double range1_aus = 10.00;
const double range2_aus = 14.00;
const double range3_aus = 17.00;
const double range4_aus = 0.00;

// Declare constant - shipping to Jupiter
const double range1_jup = 1000.00;
const double range2_jup = 2000.00;
const double range3_jup = 3000.00;
const double range4_jup = 500.00;

int main()
{
    string itemName;
    string country;
    char fragile;
    char sure;
    double orderTotal ;
    double shipCost ;
    double totalCost ;
    double fragFee = 0.00;

    // Open output file
    ofstream outFile;
    outFile.open(OUTORDER);

    // Headline
    cout << setfill('.');
    cout << setw(50) << " " << endl;
    cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << setw(50) << "\n" << endl;

    // Start inputing order info
    cout << left << "Please enter the item name (no space)" << right << setw(13)
        << ":";
    cin >> itemName ;
    cout << left << "Is the item fragile? (y=yes/n=no)" << right << setw(17)
        << ":" ;
    cin >> fragile;

    
    
    // Determine whether the item is fragile
    switch (fragile)
    {
        case 'y' :
        case 'Y' :
            fragFee = 2.00;
            break;
        case 'n' :
        case 'N' :
            fragFee = 0.00;
            break;
        default:
            cout << "\nInvalid entry, exiting" << endl;

            cout << "Press any key to continue . . ." << endl;
            cin.ignore();
            cin.get();

            return 0;
    }
    
    // Continue inputing info
    cout << left << "Please enter your order total" << right << setw(21)
        << ":" ;
    cin >> orderTotal ;
    cout << left << "Please enter destination. (usa/can/aus/Jup)" << right << setw(7)
        << ":" ;
    cin >> country;

    // Convert order total number into double type in case user types in an integer
    orderTotal = static_cast<double>(orderTotal);

    // Alter item name and destination to upper casee
    transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);
    transform(country.begin(), country.end(), country.begin(), ::toupper);
    

    // Determine shipping cost besed on destination
    if (country == "USA")
    {
        if (orderTotal <= range1)
        {
            shipCost = range1_usa;
        }
        else if (orderTotal <= range2 && orderTotal > range1)
        {
            shipCost = range2_usa;
        }
        else if (orderTotal <= range3 && orderTotal > range2)
        {
            shipCost = raneg3_usa;
        }
        else
        {
            shipCost = range4_usa;
        }
    }
    else if (country == "CAN")
    {
        if (orderTotal <= range1)
        {
            shipCost = range1_can;
        }
        else if (orderTotal <= range2 && orderTotal > range1)
        {
            shipCost = range2_can;
        }
        else if (orderTotal <= range3 && orderTotal > range2)
        {
            shipCost = range3_can;
        }
        else 
        {
            shipCost = range4_can;
        }
    }
    else if (country == "AUS")
    {
        if (orderTotal <= range1)
        {
            shipCost = range1_aus;
        }
        else if (orderTotal <= range2 && orderTotal > range1)
        {
            shipCost = range2_aus;
        }
        else if (orderTotal <= range3 && orderTotal > range2)
        {
            shipCost = range3_aus;
        }
        else
        {
            shipCost = range4_aus;
        }
    }
    else if (country == "JUP")
    {
        cout << "Are you sure you want to ship item out space? (y/n)" ;
        cin >> sure;

        switch (sure)
        {
            case('y'):
            case('Y'):

                if (orderTotal <= range1)
                {
                    shipCost = range1_jup;
                }
                else if (orderTotal <=range2 && orderTotal > range1)
                {
                    shipCost = range2_jup;
                }
                else if (orderTotal<= range3 && orderTotal > range2)
                {
                    shipCost = range3_jup;
                }
                else
                {
                    shipCost = range4_jup;
                }
                break;
            case('n'):
            case('N'):
                cout << "\nTry again, exiting" << endl;
                cout << "Press any key to continue . . ." << endl;
                cin.ignore();
                cin.get();
                return 0;
            default:
                cout << "\nInvalid entry, exiting" << endl;

                cout << "Press any key to continue . . ." << endl;
                cin.ignore();
                cin.get();
                return 0;

        }
                
    }
    else
    {
        cout << "\nInvalid entry, exiting" << endl;

        cout << "Press any key to continue . . ." << endl;
        cin.ignore();
        cin.get();

        return 0;
    }

    // Calculate shipping cost and total shipping cost
    shipCost = shipCost + fragFee;
    totalCost = shipCost + orderTotal;

    cout << fixed << showpoint;
    cout << setprecision(2);

    // Alter output statement into string
    string s1 = "Your item is";
    string s2 = "Your shipping cost is";
    string s3 = "You are shipping to";
    string s4 = "Your total shipping costs are";


    // Print out shipping statements on console
    cout << "\n" << left << s1 << right << setw(30) << "." << itemName << endl;
    cout << left << s2 << right << setw(22) << "$" << shipCost << endl;
    cout << left << s3 << right << setw(23) << "." << country << endl;
    cout << left << s4 << right << setw(14) << "$" << totalCost << endl;

    // Print out on the file
    outFile << setfill('.');
    outFile << fixed << showpoint;
    outFile << setprecision(2);
    outFile << left << s1 << right << setw(30) << "." << itemName << endl;
    outFile << left << s2 << right << setw(22) << "$" << shipCost << endl;
    outFile << left << s3 << right << setw(23) << "." << country << endl;
    outFile << left << s4 << right << setw(14) << "$" << totalCost << endl;


    cout << setfill('-');
    cout << "\n" << right << setw(49) << "-" << "Thank You!\n" << endl;

    // Clear up file
    outFile.close();

    // Execution stops
    cout << "Press any key to continue . . ." << endl;
    cin.ignore();
    cin.get();

    return 0;
    

    
}
