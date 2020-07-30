#include "recursion.h"

int main() 
{
	//recursive function call themselves up to a stopping point
	//they're to split up complicated step-y stuff into those steps

	//base cases help prevent resursion from going on forever and filling up memory

	display(3);	//displays "Hello." three times
	factorial(5);


	return 0;
}