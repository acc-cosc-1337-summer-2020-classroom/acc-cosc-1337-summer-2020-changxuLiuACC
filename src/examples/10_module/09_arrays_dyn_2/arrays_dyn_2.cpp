#include<iostream>
#include"arrays_dyn_2.h"

void display_chars(char* sequence, int size)
{
    for(int i = 0; i < size; ++i)
    {
        std::cout<<sequence[i]<<" ";
    }
}
