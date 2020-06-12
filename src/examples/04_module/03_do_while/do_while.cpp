#include "do_while.h"
#include<iostream>

//Write code for void function prompt_user to loop until
//user opts not to continue.  
void prompt_user()
{
    char choice;
    
    do
    {
        std::cout<<"Enter Y or y to continue: ";
        std::cin>>choice;
    }
    while(choice == 'y' || choice == 'Y');    //semi-colon required
}

