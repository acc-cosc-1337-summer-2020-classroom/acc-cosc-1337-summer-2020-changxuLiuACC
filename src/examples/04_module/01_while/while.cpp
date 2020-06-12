#include "while.h"
//Using a while loop write code for sum_of_squares function that accepts an int and returns  
//the sum of all the squares of that number from 1 to the number. 
//Example: sum_of_squares(4) 
//1*1 + 2 * 2 + 3*3 + 4*4 = 30
int sum_of_squares(int num)
{
    //good practice to initialize variables
    auto sum{0};
    //same as auto/int sum = 0;
    int counter{1};

    while(counter <= num)
    {
        sum += (counter * counter);
        counter++;
    }

    return sum;
}


//Using a while loop write code for display function that accepts a string and displays 
//each character of the string in a line
//Example: display("Hello")
/*
result:

H
e
l
l
0

*/

