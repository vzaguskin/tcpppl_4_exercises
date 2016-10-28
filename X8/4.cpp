/*∗1) Given two char∗ s pointing into an array, find and output the number of
characters between the two pointed-to characters (zero if they point to the
same element).*/

#include <iostream>
#include <array>
#include <random>
#include <cmath>

int main()
{
  std::array<char, 18> arr{"qwertyuiopasdfghj"};

  std::random_device rd;     // only used once to initialise (seed) engine
  std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
  std::uniform_int_distribution<int> uni(0, 17); // guaranteed unbiased

  auto it1 = arr.begin();
  auto it2 = arr.begin();

  std::advance(it1, uni(rng));
  std::advance(it2, uni(rng));

  char* p1 = &(*it1);
  char* p2 = &(*it2);



  std::cout << std::abs(p1-p2) << std::endl;

}
