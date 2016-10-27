/*(∗1) Write a program that prints signed if plain char s are signed on your implementation and
unsigned otherwise.*/

#include <iostream>
#include <limits>

int main()
{
  auto res = std::numeric_limits<char>::is_signed ? "signed" : "unsigned";
  std::cout <<  res << std::endl;
}
