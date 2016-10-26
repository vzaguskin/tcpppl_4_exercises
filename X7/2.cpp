#include <iostream>
#include <limits>

int main()
{
  auto res = std::numeric_limits<char>::is_signed ? "signed" : "unsigned";
  std::cout <<  res << std::endl;
}
