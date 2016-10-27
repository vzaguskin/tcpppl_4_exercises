/*(∗2) Draw a graph of the integer and fundamental types where a type points to
another type if all values of the first can be represented as values of the
second on every standards-conform-ing implementation. Draw the same graph for
the types on your favorite implementation.*/

//We'll output the dot file that can be visualised with graphvis
//Checking if one type includes another will be done via template
//metaprogramming mostly in compile time.

#include <limits>
#include <iostream>

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
  return range_included<A, B>() and special_values_match<A, B>() and exactness_match<A, B>();
}
