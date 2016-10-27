/*(∗1.5) What are the alignments (in number of char s) of the types mentioned in §X.7[8]?*/

#include <iostream>
#include <typeinfo>
#include <limits>

template <class A> void printlimits()
{
    std::cerr <<  typeid(A).name() << ": " << alignof(A) << std::endl;
}

template <class A, class B, class ...C> void printlimits()
{
    printlimits<A>();
    printlimits<B, C...>();
}


int main()
{
  printlimits<bool , char , short , int , long , long long , float , double ,
  long double , unsigned, unsigned long>();
}
