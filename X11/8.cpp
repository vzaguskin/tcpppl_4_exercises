/*(∗2) Write a function cat() that takes two C-style string arguments and
returns a string that is the concatenation of the arguments. Use new to find
store for the result.*/
#include <cstring>
#include <iostream>
#include <memory>

char* cat(const char* str1, const char* str2)
{
  size_t size = strlen(str1) + strlen(str2) + 1;
  char* out = new char[size];
  strcpy(out, str1);
  strcpy(out + strlen(str1), str2);
  return out;
}


int main()
{
  const char* str1 = "the first string";
  const char* str2 = "the second string";
  std::unique_ptr<char []> res(cat(str1, str2));
  std::cout << res.get() << std::endl;
}
