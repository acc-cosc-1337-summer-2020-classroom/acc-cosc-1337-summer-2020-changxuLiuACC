#include<iostream>
#include "temperature_data.h"

int main() 
{
	std::vector<Temperature> out_temps{Temperature(1, 98.9), Temperature(2, 99.5), Temperature(3, 99)};	//3 objects to be stored into file

	TemperatureData data;
	data.save_temps(out_temps);		//save temperatures into file 

	std::vector<Temperature> in_temps = data.get_temps();	//get temperatures again from file

	for(auto temp: in_temps)
	{
		std::cout<<temp.get_hour()<<" "<<temp.get_reading()<<"\n";	//print out temperatures from file
	}

	return 0;
}