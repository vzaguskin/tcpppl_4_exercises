/*(∗2) Read a sequence of words from input. Use Quit as a word that terminates
the input. Print the words in the order they were entered.
Don’t print a word twice. Modify the program to sort the words before printing
them.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<class T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& vec)
{
  os << "[";
  for (auto i:vec)
  {
    os << i << " ";
  }
  os << "]" << std::endl;
}

int main()
{
  std::vector<std::string> strs;
  for( std::string name; name != "Quit"; std::getline(std::cin, name))
  {
    //std::cout << name << std::endl;
    strs.push_back(name);
  }

  std::sort(strs.begin(), strs.end());
  auto last = std::unique(strs.begin(), strs.end());
  strs.erase(last, strs.end());

  std::cout << strs << std::endl;
}
