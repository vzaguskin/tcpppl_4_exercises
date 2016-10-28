/*(∗1) Write a function that swaps (exchanges the values of) two integers.
Use int∗ as the argument type. Write another swap function using int& as
the argument type.*/

#include <iostream>

template<class T>
void swap(T* x, T* y)
{
  T tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

template<class T>
void swapref(T& x, T& y)
{
  T tmp;
  tmp = x;
  x = y;
  y = tmp;
}

int main()
{
  int x = 5;
  int y = 7;
  swap(&x, &y);
  std::cout << x << y  << std::endl;

  swapref(x, y);
  std::cout << x << y  << std::endl;

}
