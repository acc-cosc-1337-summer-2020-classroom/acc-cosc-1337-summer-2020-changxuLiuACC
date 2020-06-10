//write include statement for switch header
#include "switch.h"

//Write code for function that accepts a num and returns a string 
//as follows:
//returns 'Option 1' when value 1
//returns 'Option 2' when value 2
//returns 'Option 3' when value 3
//returns 'Option 4' when value 4
//return 'Invalid Option' otherwise

std::string menu(int num)
{

    std::string result;

    switch(num)
    {
    case 1:
        return "Option 1";
        break;
        //break determines wheter other code cases run (if you don't use it, the next case will execute)
    case 2:
        return "Option 2";
        break;
    case 3:
        return "Option 3";
        break;
    case 4:
        return "Option 4";
        break;
    default:
        //every switch should have a default
        return "Invalid Option";
    }

    return result;
}