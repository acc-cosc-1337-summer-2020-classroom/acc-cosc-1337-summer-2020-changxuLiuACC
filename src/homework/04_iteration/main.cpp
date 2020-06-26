//write include statements
#include<iostream>
#include "dna.h"
//write using statements
using std::cout;	using std::cin;
using std::string;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	int choice;		//used to store what the user wants to do
	string dna;		//used to store the dna that is to be analyzed for GC content or complimented
	char cont;		//used to store whter the user would like to continue additional operations in the program

	do
	{
		cout<<"\nEnter 1 to get GC Content.\n";	
		cout<<"Enter 2 to get DNA Complement.\n";
		cout<<"Enter your choice: ";	//collecting user input on desired action
		cin>>choice;
		cout<<"Enter DNA String: ";		//collecting dna string from user for operations
		cin>>dna;

		if(choice == 1)
		{
			cout<<"GC Content: "<<get_gc_content(dna)<<"\n";	//calculates and prints out GC content if 1 was desired by user
		}
		else
		{
			cout<<"DNA Complement: "<<get_dna_complement(dna)<<"\n";	//creates and prints out dna complement if 2 was desired by user
		}

		cout<<"Are you done? Enter y or Y for additional DNA operations (or any other character to exit the program): ";	//prompts user if he/she would like to repeat the program
		cin>>cont;
	} while (cont == 'Y' || cont == 'y');	//if the user enters "y" or "Y", he/she indicates that more GC content analysis or DNA Complementing must be completed and will continue 
											//with the loop. However, if the user enters anything else, the user indicates he/she is done and it will not continue the loop another time
											//leading to the end of the program with the "return 0" below. 
	return 0;
}
