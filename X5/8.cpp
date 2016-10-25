/*(∗2) Initialize a vector<int> with the elements 5, 9, −1, 200, and 0.
Print it. Sort is, and print it again.
(∗1) Repeat §X.5[7] with a vector<string> initialized with "Kant" , "Plato" , "Aristotle" ,
"Kierkegard" , and "Hume" .*/

#include <iostream>
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
  std::vector<std::string> v{"Kant", "Plato", "Aristotle",
  "Kierkegard", "Hume"};

  std::cout << "Original: " << v << std::endl;
  std::sort(v.begin(), v.end());
  std::cout << "Sorted: " <<  v << std::endl;

}
