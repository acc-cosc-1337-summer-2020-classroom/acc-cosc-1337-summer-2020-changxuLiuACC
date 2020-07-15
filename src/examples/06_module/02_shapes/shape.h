//shape.h
#include<iostream>

#ifndef SHAPE_H
#define SHAPE_H

//this is in the book as well if brain requires additional knowledge to understand

class Shape     //a shape is abstract - hard to narrow down specifically what shape - so this is our ABSTRACT CLASS
{
public:
    // v needs to be a virtual function to implement polymorphism (shape class performs like other classes)
    virtual void draw() = 0;    //setting it to zero makes it a PURE VIRTUAL FUNCTIONS
    //and with at least 1 virtual function, our shape class is an abstract class - can't create an instance of it (otherwise the build will fail in runtime)
        //abstract classes are usually in italics in UML diagrams
};

#endif
