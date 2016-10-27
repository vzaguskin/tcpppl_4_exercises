/*(∗2) Draw a graph of the integer and fundamental types where a type points to
another type if all values of the first can be represented as values of the
second on every standards-conform-ing implementation. Draw the same graph for
the types on your favorite implementation.*/

//We'll output the dot file that can be visualised with graphvis
//Checking if one type includes another will be done via template
//metaprogramming mostly in compile time.

//compilation - C++14 is required for relaxed constexpr functions, but this can be rewritten in c++-11
//tested with g++-5 -std=c++14 compilation command line
//To demangle run './a.out 2>&1 | c++filt -t > graph.txt'
//To build graph run dot graph.txt -Tpng -o graph.png
//See example graph.png in the source tree

#include <limits>
#include <iostream>
#include <typeinfo>

template <class A, class B>
constexpr bool range_included()
{
  constexpr bool lowest_lower = std::numeric_limits<A>::lowest() <= std::numeric_limits<B>::lowest();
  constexpr bool max_larger =  std::numeric_limits<A>::max() >= std::numeric_limits<B>::max();
  return lowest_lower && max_larger;
}

template <class A, class B>
constexpr bool special_values_match()
{
  constexpr bool infinity_ok = (not std::numeric_limits<B>::has_infinity) or std::numeric_limits<A>::has_infinity;
  constexpr bool quiet_NaN_ok = (not std::numeric_limits<B>::has_quiet_NaN) or std::numeric_limits<A>::has_quiet_NaN;
  constexpr bool signaling_NaN_ok = (not std::numeric_limits<B>::has_signaling_NaN) or std::numeric_limits<A>::has_signaling_NaN;
  return infinity_ok and quiet_NaN_ok and signaling_NaN_ok;

}

template <class A, class B>
constexpr bool exactness_match()
{
  constexpr bool exactness_ok = (not std::numeric_limits<A>::is_exact) or std::numeric_limits<B>::is_exact;
  constexpr bool digits_ok = std::numeric_limits<A>::digits >= std::numeric_limits<B>::digits;
  return exactness_ok and digits_ok;
}


template <class A, class B>
constexpr bool A_has_B()
{
  return (typeid(A) != typeid(B)) and range_included<A, B>() and special_values_match<A, B>() and exactness_match<A, B>();
}

#define TYPES bool, char, wchar_t, char16_t, char32_t, int, short, long, float, double

template <class A, class B>
void print_graph_helper()
{
  if (A_has_B<A, B>())
    std::cerr << typeid(A).name() << " -> " << typeid(B).name() << std::endl;
}

template <class A, class B>
void print_graph()
{
  print_graph_helper<A, B>();
  print_graph_helper<B, A>();
}

template <class A, class B, class C, class ...D> void print_graph()
{
    print_graph<A, B>();
    print_graph<A, C, D...>();
}

template <class A, class B> void print_graph_complete()
{
    print_graph<A, B>();
}

template <class A, class B, class C, class ...D> void print_graph_complete()
{
    print_graph<A, B, C, D...>();
    print_graph_complete<B, C, D...>();
}


int main()
{
  std::cerr << "digraph G {" << std::endl;
  print_graph_complete<TYPES>();
  std::cerr << "}" << std::endl;
}
