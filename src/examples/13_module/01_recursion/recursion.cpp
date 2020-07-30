#include "recursion.h"
#include<iostream>
//Write code for recursive display function
void display(int count)
{
    if(count == 0)  //base case ends the recursion
    {
        return;
    }
    
    std::cout<<"Hello.\n";
    display(count - 1);  //calls itself again
}

//Write code for recursive factorial
int factorial(int n)
{
    int f;  
    int r;  //recursive return value

    if(n == 0)
    {
        return 1;   //factorial of 0 is one
    }

    std::cout<<"Load stack."<<n-1<<"\n";    //just for demonstration
    r = factorial(n-1);     //loading function calls to the stack
    f = n * r;
    std::cout<<"Unload stack n: "<<n<<" r: "<<r<<" f: "<<f<<"\n";

    return f;
}