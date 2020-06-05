#include<string>
#include<iostream>

//putting using std::string; here will make it so taht you'll just use string below each time, instead of std::string

int main() 
{
	//Create string variable and display it		
	std::string name = "John";
	std::string last_name = "Doe";

	std::cout<<name<<" "<<last_name;

	return 0;
}