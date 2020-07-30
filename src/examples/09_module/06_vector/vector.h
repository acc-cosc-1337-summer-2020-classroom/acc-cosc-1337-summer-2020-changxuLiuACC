//
#include<cstddef>
#include<stddef.h>

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

template<typename T>    //to make this a template class for any data type
class Vector
{
public:
    //FIG 1
    Vector();        //default constructor
    Vector(size_t sz);
    Vector(const Vector<T>& v);    //copy constructor (FIG 3)
    Vector<T>& operator=(const Vector<T>& v);     //copy assignment operator (FIG 4 - 5)
    Vector(Vector<T>&& v);     //move constructor (FIG --)
    Vector<T>& operator=(Vector<T>&& v);  //move assignment operator (FIG --)
    /*
    RULE OF THREE for C++98
    Every time you use dynamic memory in a class, you need a copy constructor, copy assignment constructor, and destructor!

    RULE OF FIVE for C++11
    Everything above plus the move constructor and move assignment constructor
    */
    size_t Size() const {return size;}
    T& operator[] (size_t i) {return elements[i];}    //SUBSCRIPT OPERATOR [x] to get and assign values
    T& operator[] (size_t i) const {return elements[i];}
    void set_size(size_t sz) {size = sz;}
    //CAPACITY
    size_t Capacity() const {return space;}
    //RESERVE
    void Reserve(size_t new_allocation);
    //RESIZE
    void Resize(size_t new_allocation);
    //PUSH BACK
    void PushBack(T value);
    //FIG 2
    //int get_element(size_t index) {return elements[index];}   no need with operator overload of subscript operator
    //void set_element_value(size_t index, int value) {elements[index] = value;}
    //FIG 3
    ~Vector();
private:
    //FIG 1
    size_t size;
    //CAPACITY
    size_t space;
    //FIG 2
    T* elements;
    //PUSH BACK
    const int RESERVE_DEFAULT_SIZE{8};
    const int RESERVE_DEFUALT_MULTIPLIER{2};


};

#endif

//FREE FUNCTIONS (not part of Vector class)
void use_stack_vector();
void use_dyanmic_vector();
