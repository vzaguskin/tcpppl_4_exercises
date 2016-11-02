/*
(∗2) Read a sequence of possibly whitespace-separated (name,value) pairs,
where the name is a single whitespace-separated word and the value is an
integer or a floating-point value. Compute and print the sum and mean
for each name and the sum and mean for all names.
Hint: §10.2.8.
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

template<class P1, class P2>
std::istream& operator >>(std::istream &input, std::pair<P1, P2> &p)
{
    input >> p.first;
    input >> p.second;
    return input;
}

template<class T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& vec)
{
  os << "[";
  for (auto i:vec)
  {
    os << i << " ";
  }
  os << "]";

  return os;
}

template<class P1, class P2>
std::ostream& operator <<(std::ostream& os, const std::map<P1, P2>& map)
{
  for(auto const& ent1 : map)
  {
    os << ent1.first << " : " << ent1.second << std::endl;
  }
  return os;
}



int main()
{
  std::string line;
  std::map<std::string, std::vector<double>> map;
  std::cout << "Enter name and value followed by enter for each person." <<
  " Ctrl-D to finish." << std::endl;
  while(std::getline(std::cin, line))
  {
    std::pair<std::string, double> pr;
    std::stringstream linestream;
    linestream << line ;
    linestream >> pr;
    map[pr.first].push_back(pr.second);
  }

  std::cout << "This is our map:"<< std::endl;
  std::cout << map << std::endl;

  std::cout << "Sum and mean for each key:"<< std::endl;
  for(auto const& ent1 : map)
  {
    auto sum = std::accumulate(ent1.second.begin(), ent1.second.end(), 0.);
    std::cout << ent1.first << " : " << sum << " " << sum/ent1.second.size() << std::endl;
  }

  std::cout << "Sum and mean for all keys:"<< std::endl;
  double sum;
  int count;
  for(auto const& ent1 : map)
  {
    sum += std::accumulate(ent1.second.begin(), ent1.second.end(), 0.);
    count += ent1.second.size();

  }

  std::cout  << sum << " " << sum/count << std::endl;

}
