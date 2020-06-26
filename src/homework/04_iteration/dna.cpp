#include "dna.h"
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string& dna)
{
    int GC_count{0};    //to store the GC number count (number of Gs or Cs in the DNA string)

    for(char ntide: dna)    //iterates over each character of dna - in "ntide"
    {
        if(ntide == 'G' || ntide == 'C')
        {
            GC_count++;     //increases GC content count (numerator of average) if there's a G or C
        }
    }

    //returns the average by dividng the GC number count by the length of the DNA (requires casting on dna.length(), it chops off the decimal)
    return GC_count / static_cast<double>(dna.length());   
}

/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string dna)
{
    string backwards;   //to store the backwards of dna result

    for(std::size_t i = dna.length(); i > 0; --i)    //iterates over each character of dna backwards - character in "ntide"
    {
        backwards.push_back(dna[i-1]);    //adds characters from dna to string variable backwards going in backwards direction
    }   //alternatively, backwards += dna[i-1] also could have worked. 

    return backwards;
}

/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string
*/
string get_dna_complement(string dna)
{
    string complement = get_reverse_string(dna);  //reverses the dna and stores it in variable complement (but not done yet)

    /*
        Although it would be more effective to just do -1 to complement.length() once in the for-loop header rather than each time the index of 
        complement is called, it won't work as after reaching the beginning value of complement (which would have been 0 for i), it'll attempt to 
        go to -1 before checking against the condition to stop in the loop, resulting in not good stuff as size_t can't go into negative numbers. 
    */

    for(std::size_t i = complement.length(); i > 0; --i)     //iterates over each character of complement (dna reversed backwards)
    {
        switch(complement[i-1])     //evaluates what each character is and replaces it with it's complement
        {
        case 'A':
            complement[i-1] = 'T';
            break;
        case 'T':
            complement[i-1] = 'A';
            break;
        case 'C':
            complement[i-1] = 'G';
            break;
        case 'G':
            complement[i-1] = 'C';
            break;
        default:
            return "Program incompatible with alien DNA. (Letter other than A, T, C or G detected in DNA. Please double check and try again.)";
            break;
        }
    }

    return complement;
}
