/*
Function int_overflow creates an int num variable with value 2147483647, 
add 1 to it, and returns it

@param none
@return num + 1
*/

int int_overflow()
{
    int num = 2147483647;       //maximum value an int can use
    num++;
    return num;
    
}