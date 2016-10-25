/*(∗1) Open the file of integers from §X.5[9] for reading (as an ifstream ) and read it.*/

#include <iostream>
#include <fstream>
#include <vector>

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
    const std::string filename{"out.txt"};
    std::ifstream inputFile(filename);
    std::vector<int> inputs;
    if( inputFile )
    {
      while (!inputFile.eof())
      {
        int val;
        inputFile >> val;
        inputs.push_back(val);
      }
    }
    else
    {
        std::cerr << "Failure opening " << filename << '\n';
        return -1;
    }

    std::cout << inputs << std::endl;

}
