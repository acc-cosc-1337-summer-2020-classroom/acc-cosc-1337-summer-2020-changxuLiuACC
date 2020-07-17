//temperature_data.cpp
#include "temperature_data.h"

void TemperatureData::save_temps(std::vector<Temperature>& ts)
{
    std::ofstream file_out(file_name, std::ios_base::trunc);    //all of the logic is hidden in file_out - we just need to know how to use it
    //                      ^ gotten from the const variable

    for(auto temp: ts)
    {
        file_out<<temp.get_hour();
        file_out<<" ";
        file_out<<temp.get_reading();
        file_out<<"\n";     
    }

    file_out.close();   //if we forget this, C++ closes file for us
}

std::vector<Temperature> TemperatureData::get_temps() const
{
    std::vector<Temperature> temps;
    int hour;
    double reading;

    std::ifstream read_file(file_name);

    if(read_file.is_open())     //checks if we were open the file
    {
        while(read_file>>hour>>reading)     //loops through file data and reads into hour and reading variables 
        {
            Temperature temp(hour, reading);    //creates object and puts it into vector to be returned
            temps.push_back(temp);
        }
    }

    read_file.close();  //if we forget this, C++ closes file for us

    return temps;
}