/*
(∗1.5) Write a program that reads a name (a string) and an age (an int) from the standard
input stream cin. Then output a message including the name and age to the standard output
stream cout.
*/

#include <iostream>

int main()
{
  std::string name;
  int age; //could be unsigned, but the task says int
  std::cout << "What's your name?" << std::endl;
  std::cin >> name;
  std::cout << "What's your age?" << std::endl;
  std::cin >> age;
  std::cout << "So your name is " << name << " and your age is " << age << " right?" << std::endl;
}
