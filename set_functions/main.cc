#include <iostream>
#include <string>
#include "set_operations.hpp"

template<class T>
void print_me(const std::set<T>& s)
{
  for (const auto& e : s)
    std::cout << e << ',';
  std::cout << '\n';
}

int main()
{
  auto s1 = std::set<int>{1,2,3};
  auto s2 = std::set<int>{3,4,5};
  int n = 2;

  print_me(s1 + s2); // 1,2,3,4,5,
  print_me(s1 - s2); // 1,2,
  print_me(s1 ^ s2); // 1,2,4,5,
  print_me(s1 * s2); // 4,5,6,7,8,
  print_me(s1 ^ n); // 2,3,4,5,6

  auto s3 = std::set<std::string>{"","a","b"};

  print_me(s3 ^ 0); // , #contains "empty string", (like in THLR)
  print_me(s3 ^ 4); // ,a,aa,aaa,aaaa,aaab,aab,aaba,aabb,ab,aba,abaa,abab,abb,abba,abbb,b,ba,baa,baaa,baab,bab,baba,babb,bb,bba,bbaa,bbab,bbb,bbba,bbbb,

  try
  {
    print_me(s3 ^ -4);
  }
  catch(const std::exception&)
  {
    std::cout << "Good thing we caught that!\n";
  }
  return 0;
}
