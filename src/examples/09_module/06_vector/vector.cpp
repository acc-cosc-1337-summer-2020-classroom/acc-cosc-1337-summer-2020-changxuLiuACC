#include<iostream>
#include "vector.h"

//template<typename T> can also be used on free functions to be compatible with multiple data types

template<typename T>
Vector<T>::Vector()
: size{0}, space{0}, elements{nullptr}
{

}

template<typename T>
Vector<T>::Vector(size_t sz)
: size{0}, space{sz}, elements{new T[size]}
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
template<typename T>
Vector<T>::Vector(const Vector& v)
: size{v.size}, elements{new T[v.size]}   //creates new dynamic dynamic memory (rather than pointing to the data of the other Vector)
{
    for(size_t i = 0; i < size; ++i)
    {
        elements[i] = v.elements[i];    //we have access in a copy constructor to private data
    }
}

/*
COPY ASSIGNMENT OPERATOR - FIG 5
    1 - create temporary memory
    2 - copy values from v1 into temporary memory
    3 - delete class (v2) elements memory
    4 - point elements (memory?) to temporary memory
    5 - return a reference to t h i s vector
*/
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
    if(this == &v)   //if you are the same class, like v = v
    {
        return *this;   //no need to execute the code below
    }
    
    //v1 is copied class, v2 is class being copied into (in lecture talk)

    T* temp = new T[v.size];

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

/*
MOVE CONSTRUCTOR (this is for cases like get_vector() below)
    1 - get dynamic memory from v1 (temp)
    2 - get the size 
    3 - set size and elements of temp object to 0 and nullptr
*/
template<typename T>
Vector<T>::Vector(Vector<T>&& v)
: size{v.size}, elements{v.elements}    //this elements points to the same memory as the elements of v1 (or the v parameter)
{
    //instead of creating new memory, we're just swapping the existing memory to a new pointer 
    //(or that pointer is stealing the memory from the other pointer)
    v.size = 0;
    elements = nullptr;    
    //it's not a memory leak as this new vector's elements is pointing to it 
    //(don't delete, otherwise the elements of this Vector will be a dangling pointer)
}

/*
MOVE ASSIGNEMENT OPERATOR
    1 - Deallocate orignal dynamic memory
    2 - Get the dynamic memory and size from v1
    3 - set v1.elements to nullptr
    4 - v1.size to 0
    6 - return self(this) reference
*/
template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& v)   //v is the vector in the get_vector()
{
    if(this == &v)
    {
        return *this;
    }
    
    delete elements;
    //delete[] elements;  //this operates within v1, so can just be elements
    elements = v.elements;
    size = v.size;
    v.elements = nullptr;
    v.size = 0;

    return *this;
}

/*
RESERVE adds more slots for future use
    1 - new allocation must be greater than space
    2 - create temp dyanmic memory of size new_allocation
    3 - copy values from old memory array to temp array
    5 - delete old memory
    5 - set elements to temp dyanmic memory
    6 - set space to new allocation value
*/
template<typename T>
void Vector<T>::Reserve(size_t new_allocation)
{
    if(new_allocation <= space)
    {
        return ;
    }

    T* temp = new T[new_allocation];
    for(size_t i = 0; i < size; ++i)
    {
        temp[i] = elements[i];
    }

    delete[] elements;
    elements = temp;
    //temp = nullptr;       is not necessary because once function exits, temp will be destroyed anyways
    space = new_allocation;
}

/*
RESIZE does reserve, but intializes those new elements to 0
    1 - Reserve() using new_allocation
    2 - Initialize element values beyond the size value to 0
    3 - Set space to new_allocation
*/
template<typename T>
void Vector<T>::Resize(size_t new_allocation)
{
    Reserve(new_allocation);
    
    for(size_t i = size; i < new_allocation; ++i)
    {
        elements[i] = 0;
    }

    size = new_allocation;      //so space is the filled + unfilled, while size is just the filled 
}

/*
PUSH BACK
    1 - if space 0, call reserve with reserve default size
    2 - else if size equals space, resize to space * reserve default multiplier
    3 - set element at current size to value 
    4 - increment size by 1
*/
template<typename T>
void Vector<T>::PushBack(T value)
{
    if(space == 0)  //if there's no memory allocated at all
    {
        Reserve(RESERVE_DEFAULT_SIZE);
    }
    else if (size == space)
    {
        Resize(space * RESERVE_DEFUALT_MULTIPLIER);
    }

    elements[size] = value;
    ++size;
}

template<typename T>
Vector<T>::~Vector()
{
    //std::cout<<"Releasing dynamic memory...";   //just for learning purposes - no need to do in real life (I think)
    delete[] elements;  //note the [] as its an array
    //elements = nullptr;     //note needed so it'll get deleted automatically anyways when Vector is destroyed
}

//This is because we split the class into two files:
template class Vector<int>;
template class Vector<double>;

//FREE FUNCTION (not part of Vector class)
void use_stack_vector()
{
    Vector<int> v1(3);   
    //upon function exit, the destructor will automatically execute (going out of scope?) and free up the dynamic memory

}

void use_dyanmic_vector()
{
    Vector<int>* v1 = new Vector<int>(3);     //this along won't delete memory (the destructor of Vector only deletes the elements array inside the object)
                                    //everything else, if we create dynamic memory, we must delete it ourselves

    v1[0] = v1[0];     //just to prevent "unused variable" warning

    delete v1;  //releasing dynamic memory
}

Vector<int> get_vector() //just for demonstration of move constructor
{
    Vector<int> v1(3);
    return v1;
}