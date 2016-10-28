/*(∗1) Define an array of strings in which the strings contain the names
of the months. Print those strings. Pass the array to a function that
prints those strings.*/

#include <iostream>

const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May"};

template<typename T, size_t N>
typename std::enable_if<
    !std::is_same<typename std::remove_cv<T>::type, char>::value,
std::ostream&>::type operator<<(std::ostream& os, T(&a)[N])
{
    os << '{' << a[0];
    for (size_t i = 1; i < N; ++i)
    {
        os << ',' << ' ' << a[i];
    }
    os << '}';
    return os;
}

//C++14 needed for auto function parameter, in c++11 could be (const char*(&v)[5])
void print(auto &v)
{
  std::cout << v << std::endl;
}

int main()
{
  std::cout << months << std::endl;
  print(months);
}
