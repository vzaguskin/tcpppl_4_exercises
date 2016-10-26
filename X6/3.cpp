/*(∗2) Time a loop. Write out the time in milliseconds. Do this for the
default setting of your compiler and for a setting using an optimizer
(e.g., −O2 or "release"). Be careful not to have the optimizer eliminate
your whole loop as dead code because you did not use a result.*/
#include <iostream>
#include <chrono>
int main()
{
  auto t0 = std::chrono::high_resolution_clock::now();
  int v;
  for(int i = 0; i< 1000000000; i++)
  {
    v=i;
  }

  auto v1 = v;
  auto t1 = std::chrono::high_resolution_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count() << "msec\n";

}
