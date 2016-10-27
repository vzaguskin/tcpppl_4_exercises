/*(∗1.5) Write a loop that prints out the values 4 , 5 , 9 , 17 , 12
without using an array or a vector .*/

#include <iostream>

int main()
{
  for (auto x:{4,5,9, 17, 12})
  {
      std::cout << x << " ";
  }

}
