#include<iostream>
#include "vector.h"

Vector::Vector(size_t sz)
: size(sz), elements(new int[size])
{
    for(size_t i = 0; i < sz; ++i)
    {
        elements[i] = 0;
    }
}

/*
COPY CONSTRUCTOR - FIG 3
    1 - initialize size
    2 - initialize memory for v2
    3 - copy element values from v1 into v2
*/
Vector::Vector(const Vector& v)
: size(v.size), elements{new int[v.size]}   //creates new dynamic dynamic memory (rather than pointing to the data of the other Vector)
{
    for(size_t i = 0; i < size; ++i)
    {
        elements[i] = v.elements[i];    //we have access in a copy constructor to private data
    }
}

/*
COPY ASSIGNMETN CONSTRUCTOR - FIG 5
    1 - create temporary memory
    2 - copy values from v1 into temporary memory
    3 - delete class (v2) elements memory
    4 - point elements (memory?) to temporary memory
    5 - return a reference to t h i s vector
*/
Vector& Vector::operator=(const Vector& v)
{
    //v1 is copied class, v2 is class being copied into 

    int* temp = new int[v.size];

    for(size_t i = 0; i < v.size; ++i)
    {
        temp[i] = v.elements[i];
    }

    //    v array deletion needs 
    delete[] elements;

    elements = temp;    //reassigning pointer to point to temp (with the copied vallues)
    size =  v.size;

    //this-> is to v2, references that in memory
    return *this;
    //     ^this dereferenced
}

Vector::~Vector()
{
    std::cout<<"Releasing dynamic memory...";   //just for learning purposes - no need to do in real life (I think)
    delete[] elements;  //note the [] as its an array
    //elements = nullptr;     //note needed so it'll get deleted automatically anyways when Vector is destroyed
}

//FREE FUNCTION (not part of Vector class)
void use_stack_vector()
{
    Vector v1(3);   
    //upon function exit, the destructor will automatically execute (going out of scope?) and free up the dynamic memory

}

void use_dyanmic_vector()
{
    Vector* v1 = new Vector(3);     //this along won't delete memory (the destructor of Vector only deletes the elements array inside the object)
                                    //everything else, if we create dynamic memory, we must delete it ourselves

    v1[0] = v1[0];     //just to prevent "unused variable" warning

    delete v1;  //releasing dynamic memory
}