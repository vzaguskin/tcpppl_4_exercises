/*
(∗1.5) What is the size of the array str in the following example:
char str[] = "a short string";
What is the length of the string "a short string" ?
*/
#include <iostream>
#include <cstring>

char str[] = "a short string";

int main()
{
    std:: cout << sizeof(str)/sizeof(char) << " " << std::strlen(str) << std::endl;

}
