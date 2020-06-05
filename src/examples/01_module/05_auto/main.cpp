

int main() 
{
	//auto works like python, where you don't have to declare the data type
	auto num = 1; //int data type
	auto dec = 5.5; //double
	auto ch = 'a'; //char
	//This is what they're pushing for to attract new programmers, and the industry may be moving towards using this\
	//There's no advantage to this compared to manually data typing, the compiler is very fast anyways

	//but that means you can't just initialize a variable without assigning it a value like "auto num;", because there's no way for it to 
	//know what data type (this also means you can't use it in function parameters)

	return 0;
}