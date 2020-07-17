//main
#include<iostream>
#include"employee.h"
#include "engineer.h"
#include "sales_employee.h"

using std::cout;

int main()
{
	Employee* engineer1 = new Engineer(1500, 400);		//pointers to Engineer and SalesEmployee objects created in dynamic memory
	Employee* sales1 = new SalesEmployee(40, 10, 500);

	cout<<"Engineer Pay: "<<engineer1->get_pay()<<"\n";		//displaying pay of Engineer and SalesEmployees (from above)
	cout<<"Sales Employee Pay: "<<sales1->get_pay()<<"\n";

	delete engineer1;		//clearing memory for the Engineer and SalesEmployee objects
	engineer1 = nullptr;

	delete sales1;
	sales1 = nullptr;

	return 0;
}
