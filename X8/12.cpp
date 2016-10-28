/*(∗2) Write a function that counts the number of occurrences of a pair of
letters in a string and another that does the same in a zero-terminated array
of char (a C-style string). For example, the pair "ab" appears twice in
"xabaacbaxabb" .*/

#include <iostream>
#include <string>
int count_pairs(std::pair<char, char> p, std::string str)
{
  int ret = 0;
  for(auto it = str.begin(); it < str.end(); it++)
  {
    if(*it == p.first)
    {
      if (*(it+1) == p.second)
        ret++;
    }
  }
  return ret;
}

int count_pairs(std::pair<char, char> p, const char* str)
{
  return count_pairs(p, std::string{str});
}

int main()
{
  std::cout << count_pairs(std::make_pair<char>('a', 'b'), std::string("aaaabaaaaba")) << std::endl;
  std::cout << count_pairs(std::make_pair<char>('a', 'b'), "aaaabaaaaba") << std::endl;

}
