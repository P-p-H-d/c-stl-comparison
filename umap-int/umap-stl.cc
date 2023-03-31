#include <iostream>
#include <unordered_map>

int main(void)
{
  std::unordered_map<int, int> map = { { 17, 4585}, { 42, 4856 }, {-9, 1452} };
  auto it = map.find(42);
  if (it != map.end()) {
    std::cout << "Value of 42 is " << it->second << "\n";
  }
  for(auto item : map) {
    std::cout << item.first << "->" << item.second << "\n";
  }
  return 0;
}
