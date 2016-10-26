/*(∗1.5) Use a reg ex to find all decimal numbers in a file.*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main()
{
  //create a file
  const std::string filename{"out.txt"};
  std::ofstream outFile(filename);
  outFile << "This is some text with numbers like 100, 10, 10., 14.52 and\
  newlines \n and also some more numbers like 12, 55, -2.4, 1.8";
  outFile.close();

  //read a file and find decimal numbers
  std::ifstream inFile(filename);
  auto lineno = 0;
  const std::regex pat("\\-{0,1}\\d+\\.\\d+{0,1}");

  for(std::string line; std::getline(inFile, line);)
  {
    std::cout << lineno++ << ": ";
    std::sregex_iterator it(line.begin(), line.end(), pat);
    std::sregex_iterator it_end;
    while(it != it_end)
    {
      std::cout << (*it++)[0] << " ";
    }

    std::cout << std::endl;
  }
}
