/*(∗2) Write a function itoa(int i, char b[]) that creates a string
representation of i in b and returns b .*/
#include <iostream>
#include <list>

void splitNumber(std::list<int>& digits, int number) {
  if (0 == number) {
    digits.push_back(0);
  } else {
    while (number != 0) {
      int last = number % 10;
      digits.push_front(last);
      number = (number - last) / 10;
    }
  }
}


template<typename T, size_t size>
typename std::enable_if<
    !std::is_same<typename std::remove_cv<T>::type, char>::value,
std::ostream&>::type operator <<(std::ostream& os, T(&arr)[size])
{
  os << (T*)arr;
}


constexpr auto dchars = "0123456789";


template<int size>
auto itoa(int i, char (&b)[size])
{
  std::list<int> digits;
  splitNumber(digits, i);
  if(digits.size() + 1 > size)
  {
    std::cerr << "size is too small" << std::endl;
    return b;
  }
  char* c=b;
  for (auto x:digits)
    *c++=dchars[x];
  *c=0;
  return b;
}

int main()
{
  char b[10];
  std::cout << itoa(1234, b) << std::endl;
}
