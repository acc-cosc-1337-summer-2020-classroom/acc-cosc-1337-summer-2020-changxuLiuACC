#include<iostream>
#include "vector.h"

using std::cout;

int main()
{
    ///*  //LECTURE 7.23.2020     Testing out the Vector class    ------------------------------------------------------------------
    Vector v(3);

    for(size_t i = 0; i < 3; ++i)
    {
        cout<<v[i]<<"\n";   //this only prints out 0s because of the hard coded 3 (instead of v.Size())
    }
    cout<<"\n";
    v.PushBack(5);
    v.PushBack(120);

    for(size_t i = 0; i < v.Size(); ++i)
    {
        cout<<v[i]<<"\n";
    }
    //------------------------------------------------------------------------------------------------------------------------  */

    /*  //  LECTURE 7.23.2020   Demonstration of Rvalues and Lvalues for Move Constructor   --------------------------------------
    int lvalue{3};     //this is an lvalue - we can reference it (it has an address and we can access it)
    int& num_ref = lvalue;     //take a reference of the address
    cout<<num_ref<<"\n";

    //rvalues have an address, we can't reference it
    //                 v this is an rvalue
    //int& num_5_ref = 5;   //can't do this
    //5 = num

    int&& num_5_ref = 5;    //force rvalue reference - this is used to make a move constructor
    cout<<"Rvalue ref: "<<num_5_ref<<"\n";
    num_5_ref = 10;
    cout<<"Rvalue ref: "<<num_5_ref<<"\n";
    //----------------------------------------------------------------------------------------------------------------------    */

    /*  //LECTURE 7.21.2020     Demonstration of Difficulties in Using Dynamic Memory   ------------------------------------------
    //use_stack_vector();
    use_dyanmic_vector();
    //----------------------------------------------------------------------------------------------------------------------    */

    return 0;
}
