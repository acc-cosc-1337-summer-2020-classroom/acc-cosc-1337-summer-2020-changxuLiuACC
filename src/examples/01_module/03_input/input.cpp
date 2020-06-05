//cpp
//write header file include

/*
Function get_total returns the product of parameters units and rate

@param int      - the number of units
@param double   - the rate per unit
@return the product of units and rate
*/

double get_total(int units, double rate)
{
    //putting everything here (cin s and stuff) wouldn't allow us to test as there wouldn't be anything to enter the data
    
    double total = units * rate;
    //this variable will only exist in memory within the function, once the function
    //finishes, it won't be in memory anymore.
    return total;
    
    //return units * rate; might work, but Prof. wanted to demonstrate variables
}