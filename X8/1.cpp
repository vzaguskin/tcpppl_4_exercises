/*(∗1) Write declarations for the following: a pointer to a character,
an array of 10 integers, a reference to an array of 10 integers,
a pointer to an array of character strings, a pointer to apointer to a character,
a constant integer, a pointer to a constant integer, and a constant pointer to
an integer. Initialize each one.*/

#include <initializer_list>
#include <iostream>
#include <utility>
#include <typeinfo>
#include <tuple>

char* p = nullptr;
int arr[10];
const char* csarr[] = {"str1", "str2", "str3"};
auto pca = &csarr;
char** pp = &p;
const int i{8};
int j{5};
int const * pi{&i};
int* const pi2{&j};

auto t = std::make_tuple(p, arr, pca, pp, i, pi, pi2);

template<int index, typename... Ts>
 struct print_tuple {
     void operator() (std::tuple<Ts...>& t) {
         std::cout << typeid(std::get<index>(t)).name() << " " << std::endl;
         print_tuple<index - 1, Ts...>{}(t);
     }
 };

 template<typename... Ts>
 struct print_tuple<0, Ts...> {
     void operator() (std::tuple<Ts...>& t) {
         std::cout << typeid(std::get<0>(t)).name() << " "  << std::endl;
     }
 };

 template<typename... Ts>
 void print(std::tuple<Ts...>& t) {
     const auto size = std::tuple_size<std::tuple<Ts...>>::value;
     print_tuple<size - 1, Ts...>{}(t);
 }

int main()
{
  print(t);

};
