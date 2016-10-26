/*(∗1.5) Write a program that prints the sizes of the fundamental types,
a few pointer types, and a few enumerations of your choice.
Use the sizeof operator.*/

#include <iostream>
#include <typeinfo>

template <class A> void sizeofs()
{
    std::cerr <<  typeid(A).name() << ": "<< sizeof(A) << std::endl;
}

template <class A, class B, class ...C> void sizeofs()
{
    sizeofs<A>();
    sizeofs<B, C...>();
}

enum Color { red, green, blue };
enum access_t { read = 1, write = 2, exec = 4 };

int main()
{
  sizeofs<bool, char, unsigned char, int, float, double, int*, char*,
       Color, access_t >();
}
