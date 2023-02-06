#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main(void)
{
  std::vector<std::string> array = { "World", "Hello", "!" };
  std::sort(array.begin(), array.end());
  for(auto item : array) {
    std::cout << item << "\n";
  }
  return 0;
}
