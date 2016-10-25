/*(∗2) Repeat the histogram drawing example from §5.6.3 for a
normal_distribution and 30 rows.*/

//Using binominal distribution as an int version of normal.
//Could use normal and perform rounding instead.


#include <random>
#include <functional>
#include <vector>
#include <iostream>

int main()
{
  std::random_device rd;
  std::mt19937 gen(rd());

  auto rnd = std::bind(std::binomial_distribution<>{30,0.5}, gen);

  std::vector<int> histogram(30);

  for (int i=0; i!=200; ++i)
      ++histogram[rnd()];

  // make a vector of size 5
  // fill histogram with the frequencies of numbers [0:4]
  for (int i = 0; i!=histogram.size(); ++i)
  {
    // write out a bar graph
    std::cout << i << '\t';
    for (int j=0; j!=histogram[i]; ++j) std::cout << '*';
    std::cout << std::endl;
  }
}
