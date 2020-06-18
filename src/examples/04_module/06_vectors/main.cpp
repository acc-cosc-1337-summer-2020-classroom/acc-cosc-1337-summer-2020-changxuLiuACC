#include "vec.h"
#include<vector>
#include<iostream>

using std::vector;

int main() 
{

	vector<int> num;

	if(num.empty())
	{
		std::cout<<"is empty\n";
	}

	vector<int> num1(5);
	//num1.clear() 		would clear the vector

		for (auto n: num1)
	{
		std::cout<<n<<"\n";
	}

	vector<char> char1(5, 'z');		//5 elements with value z

		for (auto c: char1)
	{
		std::cout<<c<<"\n";
	}

	vector<double> dubs{1.5, 2.5};
	vector<std::string> names {"joe", "john", "Mary"};
	names.push_back("Jill");

	for (auto n: names)
	{
		std::cout<<n<<"\n";
	}

	return 0;
}