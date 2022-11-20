#include <iostream>
#include <vector>
#include <algorithm>
#include <gmpxx.h>

int main(void)
{
  std::vector<mpz_class> array = { 17, 42, 9 };
  std::sort(array.begin(), array.end());
  for(auto item : array) {
    std::cout << item << "\n";
  }
  return 0;
}
