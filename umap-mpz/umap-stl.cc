#include <iostream>
#include <unordered_map>
#include <gmpxx.h>

template<> struct std::hash<mpz_class>
{
  std::size_t operator()(mpz_class const& s) const noexcept
  {
    mpz_srcptr z = s.get_mpz_t();
    mp_size_t  n = z->_mp_size;
    mp_limb_t *p = z->_mp_d;
    size_t hash = 0;
    if (n <= 0) {
      hash ^= 0x7F5C1458;
      if (n == 0) {
        return hash;
      }
      n = -n;
    }
    while (n-- > 0) {
      hash ^= *p++;
    }
    return hash;
  }
};

int main(void)
{
  std::unordered_map<mpz_class, mpz_class> map = { { 17, 4585}, { 42, 4856 }, {-9, 1452} };
  auto it = map.find(42);
  if (it != map.end()) {
    std::cout << "Value of 42 is " << it->second << "\n";
  }
  for(auto item : map) {
    std::cout << item.first << "->" << item.second << "\n";
  }
  return 0;
}
