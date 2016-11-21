/*
(∗2) Implement and test these functions: strlen() , which returns the length of
a C-style string; strcpy() , which copies a C-style string into another; and
strcmp() , which compares two C-style strings. Consider what the argument types
and return types ought to be. Then compare your functions with the standard
library versions as declared in <cstring> ( <string.h> ) and as specified in
§43.4.
*/

#include <iostream>

template<size_t N>
int strlen(const char (&)[N])
{
  return N-1;
}

int strlen(const char* ptr)
{
  const char* p = ptr;
  for(; *ptr != '\0'; ptr++);
  return ptr - p;
}

void strcpy(const char* src, char* dst)
{
  while(*src != '\0')
  {
    *(dst++) = *(src++);
  }
  *(++dst) = '\0';
}
int main()
{
  char str1[] = "str1";
  char* str2 = new char[20];
  strcpy("mamapapa", str2);

  std::cout << str1 << " " << str2 << " " << strlen(str1) << " " << strlen(str2);


}
