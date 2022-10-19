#include <iostream>
#include "function.h"
using namespace std;

//Check if a certain integer exists in the array if the number is present return the index where the number is present.
int find(int*& arr, int arrLength, int x)
{

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == x)
        {

            return i;
        }

    }
    return -1;
}

//A function which intakes an index of an array and remove the integer corresponding to that index.
void delete_element(int*& arr, int pos, int& size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = arr[i];
    }
    for (i = 0; i < pos; i++)
    {
        arr[i] = arr[i];
    }
    for (i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size = size - 1;
}

//A function that adds a new integer to the end of the array
void add_element(int*& arr, int num, int& size)
{
    size++;
    int* newA = new int[size];
    for (int i = 0; i < size - 1; i++)
    {
        newA[i] = arr[i];
    }
    newA[size - 1] = num;
    delete[] arr;
    arr = newA;
    newA = NULL;
}



//A function that can modify the value of an integer when 
//called with the index of the integer in the array and return the new value and old value back to the user
void change_val(int*& arr, int pos, int size, int newVal)
{
    if (pos < size)
    {
        cout << "The old value at that index was [" << arr[pos] << "].\nThe new value is now: [";
        arr[pos] = newVal;
        cout << arr[pos] << "].\n" << endl;
    }
    else
    {
        cout << "Sorry, the position you wanted does not exist in the array." << endl;
    }
}

void display(int*& arr, int size)
{
    for (int j = 0; j < size; j++)
    {
        cout << "[" << arr[j] << "] ";
    }
}