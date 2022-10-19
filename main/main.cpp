//Jaeni Lee
//ASSIGNMENT 01
#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>
#include "function.h"
using namespace std;


int main()
{
    ifstream fin;
    fin.open("sample.txt");
    const int r = 100;
    int* user = new int[r];
    int target;
    int deletePos = 0;
    int add = 0;

    int count = 0;
    while (fin.good())
    {
        int numbers;

        //testing with JUST FOUR ELEMENTS IN AN ARRAY
        for (int i = 0; i < r; i++)
        {
            fin >> numbers;
            user[i] = numbers;
            count++;
        }
    }
    cout << endl << endl;

    cout << "Here is the list: \n" << endl;
    display(user, count);
    cout << endl << endl;

    //Testing out the first member funtion: find()
    cout << "What number are you looking for?" << endl;
    cin >> target;
    int n = find(user, count, target);


    while (n < 0)
    {
        cout << "\nSorry the number you were looking for does not exist in the list of elements." << endl;
        cout << "Please enter another number you are looking for: " << endl;
        cin >> target;
        n = find(user, count, target);
    }
    if (n > -1)
    {
        cout << "\nThe number you are looking for is in position " << n << "." << endl << endl;
    }
    //Testing for the removal of the position in the array: delete_element()

    cout << "\nWhat number position do you want to delete?" << endl;
    cin >> deletePos;

    while (deletePos >= count)
    {
        cout << "Sorry, the position you wanted to delete does not exist. Enter another number: " << endl;
        cin >> deletePos;
    }
    delete_element(user, deletePos, count);
    cout << "Here is the list with the deleted element in that specified position:\n";
    display(user, count);
    cout << endl << endl;

    //Testing for the addition of an element at the end of the array: add_element()

    // **** NEW CHANGE **** adding try and catch blocks to the user inputs 
    bool v = true;
    while (v)
    {
        try
        {
            cout << "What number do you want to add at the end of the array?" << endl;
            cin >> add;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                throw runtime_error("Invalid input for value to add at the end of the array");
            }
            add_element(user, add, count);
            display(user, count);
            cout << endl << endl;
            v = false;
       
        }
        catch (runtime_error& ex)
        {
            cout << ex.what() << endl;
        }
        catch (...)
        {
            cout << "Invalid number\n";
            cin.clear();
            abort();
        }
    }

    //Testing for the position where the user wants to switch the values with the new one: change_val()

    // **** NEW CHANGE **** adding try and catch blocks to the user inputs 
    
    while (true)
    {
        
        try
        {
            int pos_value, newVal;
            cout << "What position would you like to change the numbers of?" << endl;
            cin >> pos_value;

            if (pos_value >= count)
            {

                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                throw runtime_error("Invalid input for the specified position. Position is from 0 - 99.");
            }

            cout << "\nWhat is your new value?" << endl;
            cin >> newVal;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                throw runtime_error("Invalid input for the modification of the values");
            }


            change_val(user, pos_value, count, newVal);
            display(user, count);
            return false;
        }
        catch (runtime_error& ex)
        {
            cout << ex.what() << endl << endl;
        }
        catch (...)
        {
            cout << "Invalid\n";
            cin.clear();
            abort();
        }
        
    }


    //closing the file
    fin.close();

    return 0;
}