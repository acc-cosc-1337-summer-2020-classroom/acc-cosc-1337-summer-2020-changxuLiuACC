//temperature_data.h
#include<fstream>
#include<string>
#include<vector>
#include "temperature.h"

#ifndef TEMPERATURE_DATA_H
#define TEMPERATURE_DATA_H

class TemperatureData
{
public:
    void save_temps(std::vector<Temperature>& ts);      //saves a list of temps to file
    std::vector<Temperature> get_temps() const;         //reads the list from file, creates Temperature class objects, adds to a vector
private:
    const std::string file_name{"temperature.dat"};     //if it doesn't exist, it will create the file
};

#endif
