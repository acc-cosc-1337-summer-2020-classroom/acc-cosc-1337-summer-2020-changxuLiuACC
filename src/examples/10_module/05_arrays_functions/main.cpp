//main
#include<iostream>
#include<iomanip>
#include "arr_functions.h"

using std::cout;

typedef double scores[3];	//list of 3 scores - for convenience

int main() 
{
	//LECTURE 7.9.2020	-------------------------------------------------------------------------------------------------------
	//TYPEDEF (look above)	---------------------------------------------------------------------------------------------------
	scores grades{75, 85, 95};
	double numbers[]{50, 60, 90};

	//std::size_t unsigned_number;	//data type of iterating through arrays

	for(auto grade: grades)
	{
		cout<<grade<<"\n";
	}

	//display_array FUNCTION	-----------------------------------------------------------------------------------------------
	//cout<<"\n";
	//display_array(numbers, 3);

	//2D ARRAYS ---------------------------------------------------------------------------------------------------------------
	double table[ROWS][COLS]{
									//	   0	1	 2	  3
									/*0*/{6.5, 3.6, 4.5, 7.7}, 
									/*1*/{9.1, 8.2, 3.9, 4.9}, 
									/*2*/{8.5, 5.6, 5.4, 2.7}
								};
	
	cout<<table[1][2]<<"\n";	//3.9
	cout<<table[0][0]<<"\n";	//6.5

	display_table(table, ROWS);

	//TIMES TABLE 2D ARRAY EXAMPLE
	int times_table[10][10];		//creates 100 sequential slots in stack memory

	for(int r = 0; r < 10; ++r)
	{
		for(int c = 0; c < 10; ++c)
		{
			times_table[r][c] = (r+1) * (c+1);		//populates/assign value to each element through nested for-loop
		}
	}

	for(int r = 0; r < 10; ++r)
	{
		for(int c = 0; c < 10; ++c)
		{
			cout<<std::setw(4)<<times_table[r][c];		//displaying the times_table through nested for-loop
		}
		cout<<"\n";
	}

	//3D ARRAYS	---------------------------------------------------------------------------------------------------------------
	double sections[SECTIONS][SEAT_ROW][SEAT_COL];

	set_sections_pricing(sections, 10);
	cout<<"\n";
	display_sections(sections);

	//-------------------------------------------------------------------------------------------------------------------------


	return 0;
}
