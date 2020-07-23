//
#include<cstddef>
#include<stddef.h>

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

class Vector
{
public:
    //FIG 1
    Vector(size_t sz);
    Vector(const Vector& v);    //copy constructor (FIG 3)
    Vector& operator=(const Vector& v);     //copy assignment constructor (FIG 4 - 5)
    /*
    RULE OF THREE for C++98
    Every time you use dynamic memory in a class, you need a copy constructor, copy assignment constructor, and destructor!
    */
    size_t Size() const {return size;}
    int& operator[] (size_t i) {return elements[i];}    //SUBSCRIPT OPERATOR [x] to get and assign values
    int& operator[] (size_t i) const {return elements[i];}
    void set_size(size_t sz) {size = sz;}
    //FIG 2
    //int get_element(size_t index) {return elements[index];}   no need with operator overload of subscript operator
    void set_element_value(size_t index, int value) {elements[index] = value;}
    //FIG 3
    ~Vector();
private:
    //FIG 1
    size_t size;
    //FIG 2
    int* elements;
};

#endif

//FREE FUNCTION (not part of Vector class)
void use_stack_vector();
void use_dyanmic_vector();
