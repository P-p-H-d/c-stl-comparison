#include <iostream>
#include <string>
#include <unordered_map>

int main(void)
{
  std::unordered_map<std::string, std::string> map = { { "Hello", "LIB"}, { "Welcome", "Program" }, {"Sincerely", "Your map"} };
  auto it = map.find("Hello");
  if (it != map.end()) {
    std::cout << "Value of 'Hello' is " << it->second << "\n";
  }
  for(auto item : map) {
    std::cout << item.first << "->" << item.second << "\n";
  }
  return 0;
}
