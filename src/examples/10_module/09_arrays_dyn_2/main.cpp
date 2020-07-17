//main
#include<iostream>
#include<cctype>
#include<cstring>
#include<string>
#include "arrays_dyn_2.h"

using std::cout;	using std::cin;

int main() 
{
	//LECTURE 7.16.2020		
	///*	//STRING TO INTEGER (and other number) CONVERSIONS	-------------------------------------------------------------------------------
	int i = std::stoi("5");		//string to integer
	cout<<"Conversion: "<<i<<"\n";

	///*	//C-STRINGS		-------------------------------------------------------------------------------------------------------------------
	const int SIZE = 26;	//remember: this needs to be size+1 to account for null terminator
	char name[SIZE];		//char array
	cin.getline(name, SIZE);	//used to still count spaces and full name (and adds null terminator for us)
	cout<<"Name: "<<name<<"\n";
	
	int indx = 0;
	while(name[indx] != '\0')
	{
		cout<<name[indx]<<" ";
		indx++;
	}
	cout<<"\n";

	indx = 0;
	char last_name[SIZE] = "Eisenhower";	//automatically adds null terminator
	while(last_name[indx] != '\0')
	{
		cout<<last_name[indx]<<" ";
		indx++;
	}
	cout<<"\n";

	indx = 0;
	char first_name[SIZE];
	first_name[0] = 'J';
	first_name[1] = 'o';
	first_name[2] = 'e';
	first_name[3] = '\0';	//when we do this, we must set the null terminator ourselves - DON'T FORGET!!!
	cout<<"First Name: "<<first_name<<"\n";		//no need for loops! (previous were demonstration)
	
	first_name[0] = 'j';	//modifies original
	cout<<"First Name: "<<first_name<<"\n";	

	//POINTERS TO C-STRINGs
	char* ptr_last_name = last_name;	//just pointing to exisitng memory
	cout<<"Last name via pointer: "<<ptr_last_name<<"\n\n";		//*ptr_last_name would only print E (first char in C-string)

	//C-STRING FUNCTIONs
	display_chars(first_name, 4);

	cout<<"Length of first_name: "<<strlen(first_name)<<"\n";	//notice strlen() is a free function, not part of a class
	cout<<"Length of last_name: "<<strlen(last_name)<<"\n";

	strcat(first_name, last_name);		//concatenates them together into first_name (without space though)
	//WARNING: when concatenating, we must ensure that the first argument (where its stored) has enough space to fit all of the chars
	cout<<"Concatenated: "<<first_name<<"\n";

	//strcmp(string1, string2) does a character by character comparison (ASCII value) and returns a bool

	//--------------------------------------------------------------------------------------------------------------------------------	*/

	/*	//INTRO TO CHARs	---------------------------------------------------------------------------------------------------------------
	char letter = 'A';
	
	if(isupper(letter))		//not a class, not letter.isupper()
	{
		cout<<"Upper\n";
	}
	if(islower(letter))
	{
		cout<<"Lower\n";
	}
	if(isalpha(letter))
	{
		cout<<"Alpha\n";
	}
	if(isdigit(letter))
	{
		cout<<"Digit\n";
	}
	
	cout<<"Convert a character to lower: "<<tolower(letter)<<".\n";
	cout<<"Convert a character to upper: "<<toupper(letter)<<".\n";
	//--------------------------------------------------------------------------------------------------------------------------------	*/

	return 0;
}