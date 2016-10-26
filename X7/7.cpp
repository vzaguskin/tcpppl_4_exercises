/*(∗1.5) Write a program that prints out the letters 'a' .. 'z' and the digits
'0' .. '9' and their integer values. Do the same for other printable characters.
Do the same again but use hexadecimal notation.*/

#include <iostream>
#include <cctype>
#include <limits>

int main()
{
  for(char c = std::numeric_limits<char>::min(); c < std::numeric_limits<char>::max(); ++c)
  {
    if (std::isprint(c))
      std::cout << c << " " << int(c)  << " 0x" << std::hex << int(c)  << std::dec << std::endl;
  }
}
