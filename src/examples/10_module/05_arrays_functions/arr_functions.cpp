//arr_functions.cpp
#include<iostream>
#include<iomanip>
#include "arr_functions.h"

using std::cout;

//define iterate_array and loop through with ++ increment


void display_array(const double array[], int size)      //if you pass an array into a function, you pass the original regardless of &
{                 
    
    //array[1] = 100;     //to purposely make the test case fail - THIS POINTS TO THE ORIGINAL
    for(int i = 0; i < size; ++i)
    {
        cout<<array[i]<<"\n";
    }
}

void display_table(const double table[][COLS], int rows)
{
    for(int r=0; r < rows; ++r)         //could've just used the ROWS variable as well like COLS (although with 2D array, must specify number, and just used the variable for it)
    {
        for(int c=0; c < COLS; ++c)
        {
            cout<<std::setw(5)<<table[r][c];
        }
        cout<<"\n";
    }
}

double get_average(double array[], int size)
{
    auto sum{0.0};
    
    for(int i = 0; i < size; ++i)
    {
        sum += array[i];
    }

    return sum/size;
}

void set_sections_pricing(double seating[][SEAT_ROW][SEAT_COL], double price)
{
    for(int s = 0; s < SECTIONS; ++s)
    {
        for(int r = 0; r < SEAT_ROW; ++r)
        {
            for(int c = 0; c < SEAT_COL; ++c)
            {
                seating[s][r][c] = price * r + 1;
            }
        }
    }
}

void display_sections(double seating[][SEAT_ROW][SEAT_COL])
{
    for(int s = 0; s < SECTIONS; ++s)
    {
        cout<<"Section: "<<s+1<<"\n";
        for(int r = 0; r < SEAT_ROW; ++r)
        {
            cout<<"\tRow: "<<r+1<<"\t\t";
            for(int c = 0; c < SEAT_COL; ++c)
            {
                cout<<std::setw(5)<<seating[s][r][c];
            }
            cout<<"\n";
        }
    }
}
