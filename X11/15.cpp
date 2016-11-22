/*(∗1) Copy all even non-zero elements of an int[] into a vector<int> .
Use a pointer and ++ for the traversal.*/
#include <vector>
#include <iostream>

template<class T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& vec)
{
  os << "[";
  for (auto i:vec)
  {
    os << i << " ";
  }
  os << "]";

  return os;
}

template<size_t N>
void copyEvenNonzero(int (&arr)[N], std::vector<int>& vec )
{
  for(int i=0; i<N; i++) //i+=2 would be better, but the task says ++
  {
    if(!(i%2) && arr[i])
      vec.push_back(arr[i]);
  }

}

int main()
{
  int arr[] = {1, 0, 0, 1, 1, 2, 2, 0, 3, 4, 5};
  std::vector<int> vec;
  copyEvenNonzero(arr, vec);

  std::cout << vec << std::endl;
}
