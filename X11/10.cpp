/*(∗2) Write a function rev() that takes a C-style string argument and reverses
the characters in it. That is, after rev(p) the last character of p will be
the first, etc.*/
#include <cstring>
#include <iostream>

//in-place reverse
char* rev(char* src)
{
  auto len = strlen(src);
  for(int i=0; i< len/2; i++)
    std::swap(src[i], src[len - i - 1]);
  return src;
}

int main()
{
  char str1[] = "1234";
  char str2[] = "12345";
  std::cout << rev(str1) << " " << rev(str2) << std::endl;
}
