//#include<string> not needed because already done in header file
#include<iostream>
#include "for_ranged.h"

int main() 
{
	/*
	std::string name = "John";
	
	loop_string_w_index(name);
	std::cout<<"\n\n";
	loop_string_w_for_range(name);
	*/

	/*
	char letter = 'a';
	char letter2 = 'b';

	letter2 == letter;	//

	//Creating strings
	std::string name1;
	std::cout<<"name1"<<name1<<"\n";
	std::string name = "joe";	//create string assign joe to it
	std::cout<<"name"<<name<<"\n";
	std::string name2{"john"};
	std::cout<<"name2"<<name2<<"\n";
	std::string name3(9, 'a');
	std::cout<<"name3"<<name3<<"\n";

	//string operations
	if(name1 == name)
	{
		std::cout<<"same";
	}

	name1 += name;		//0 = j, 1 = o, and 2 = e
	std::cout<<"name1 "<<name1<<"\n";
	std::cout<<"element one of name: "<<name1[1]<<"\n";
	name1[1];
	name.push_back('y');	//name is now joey
	std::cout<<"name"<<name<<"\n";
	name2.insert(3, "n");	//john would be johnn
	std::cout<<name2;
	name2.insert(4, "y");	//john would be johny
	name2.push_back('y');
	std::cout<<"name2"<<name2<<name2.size()<<"\n";

	for(auto n: name2)
	{
		n = 'a';
		//std::cout<<n<<"\n";
	}
	std::cout<<"name2 "<<name2<<" size "<<name2.size()<<"\n";

	for(std::size_t i = 0; i < name.size(); ++i)
	{
		name[i] = 'a';
	}
	*/

	std::string last_name;
	std::cout<<"Enter last name: ";
	//std::cin>>last_name;		//can't deal with spaces
	std::getline(std::cin, last_name);
	std::cout<<last_name;
	

	return 0;
}
