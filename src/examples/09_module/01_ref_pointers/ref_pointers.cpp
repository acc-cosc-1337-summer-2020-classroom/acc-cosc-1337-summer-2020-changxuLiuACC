//ref_pointers.cpp
#include "ref_pointers.h"


void val_ref_ptr_cptr(int n1, int& n2, int* n3, int* const n4)
{
    n1 = 0;     //value makes a copyu - doesn't modify orignal
    n2 = 5;     //reference modifies original
    *n3 = 10;   //pointers modify the original
    //n4 = 20;  cannot modify a constant
}

int* get_int_pointer()
{
    /*
    int n{7};
    int* ptr = &n;
    return ptr;     //problem: n is deleted from memory upon leaving the function, leading to a pointer to an invalid address (variable no longer exists)
    */

    //to fix, use dynamic memory (heap), as it stays until we delete it
    int* n = new int(7);
    return n;       //now n will exist until we delete it (which we should to at some point to avoid memory leaks)
}
