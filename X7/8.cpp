/*(∗2) What, on your system, are the largest and the smallest values of the
following types: bool , char , shor t , int , long , long long , float , double ,
long double , unsigned and unsigned long .*/

#include <iostream>
#include <typeinfo>
#include <limits>

template <class A> void printlimits()
{
    std::cerr <<  typeid(A).name() << ": " << std::numeric_limits<A>::min() << " " << std::numeric_limits<A>::max() << std::endl;
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
