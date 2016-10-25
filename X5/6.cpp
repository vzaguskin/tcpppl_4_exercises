/*(∗1.5) Redo §X.5[5], storing several (name,age) pairs in a class.
Doing the reading and writing using your own >> and << operators*/

#include <iostream>
#include <vector>
#include <sstream>
using NAPair = std::pair<std::string, int>;

std::istream& operator >>(std::istream &input, NAPair &p)
{
    input >> p.first;
    input >> p.second;
    return input;
}

template<class T, class U>
std::ostream& operator <<(std::ostream& os, const std::pair<T, U>& p)
{
  os << "(" << p.first << ", " << p.second << " )";
}


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

  std::vector<NAPair> persons;
  NAPair p;
  std::string line;
  std::cout << "Enter name and value followed by enter for each person." <<
  " Ctrl-D to finish." << std::endl;
  while (std::getline(std::cin, line))
  {
    std::stringstream linestream;
    linestream << line ;
    linestream >> p;
    persons.push_back(p);
    //std::cout << p << std::endl;
  }

  std::cout << "Result:" << persons;
}
