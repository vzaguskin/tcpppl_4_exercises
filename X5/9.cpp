/*(∗1) Open a file for writing (as an ofstream ) and write a few hundred integers to it.*/

#include <iostream>
#include <fstream>

int main()
  {
    const std::string filename{"out.txt"};
    std::ofstream outputFile(filename);
    if( outputFile )
    {
        for(int i = 0; i < 800; i++)
          outputFile << i << " ";
    }
    else
    {
        std::cerr << "Failure opening " << filename << '\n';
        return -1;
    }

}
