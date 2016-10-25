/*(∗1.5) Write a program with two tread s: one that writes hello
every second and one that writes world! every second.*/

#include <thread>
#include <iostream>
int main()
{
  std::thread t([](){
        while(true)
        {
          std::cout << "Hello\n";
          std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    std::thread t1([](){
      while(true)
      {
        std::cout << "World\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
      }
      });

  t.join();
  t1.join();
}
