#include <stdio.h>
#include <gmp.h>

// WORKAROUND: Needs to encapsulate mpz_t within a C struct
typedef struct {
  mpz_t Z;
} mpz_z;

#define i_type         umap_mpz
#define i_key          mpz_z
#define i_keydrop(z)   mpz_clear(z->Z)
#define i_keyclone(z)  __extension__ ({ mpz_z Z; mpz_init_set(Z.Z, z.Z); Z; })  // WORKAROUND: needs to use GNU C extension or static inline functions to match GMP prototype.
#define i_hash(z)      (size_t) *(z)                      // WORKAROUND: i_hash only works on keyraw (not on the base type): the hash cannot therefore handle the full mpz_t range.
#define i_eq(a,b)      ((a) == (b))              // WORKAROUND: i_eq only works on keyraw (not on the base type)
#define i_keyraw       long int
#define i_keyfrom(ui)  __extension__ ({ mpz_z Z; mpz_init_set_si(Z.Z, ui); Z; })
#define i_keytoraw(z)  mpz_get_si(z->Z)
#define i_val          mpz_z
#define i_valdrop(z)   mpz_clear(z->Z)
#define i_valclone(z)  __extension__ ({ mpz_z Z; mpz_init_set(Z.Z, z.Z); Z; })
#define i_valraw       long int
#define i_valfrom(ui)  __extension__ ({ mpz_z Z; mpz_init_set_si(Z.Z, ui); Z; })
#define i_valtoraw(z)  mpz_get_si(z->Z)
#include <stc/hmap.h>

#include <stc/algorithm.h>

int main(void)
{
  umap_mpz map = { 0 };

  umap_mpz_result res = umap_mpz_emplace_or_assign(&map, 17, 4585);
  if (res.inserted != true) {
    abort();
  }
  res = umap_mpz_emplace_or_assign(&map, 42, 4856);
  if (res.inserted != true) {
    abort();
  }
  res = umap_mpz_emplace_or_assign(&map, -9, 1452);
  if (res.inserted != true) {
    abort();
  }
  const umap_mpz_value *it = umap_mpz_get(&map, 42);
  if (it != NULL) {
    gmp_printf("Value of 42 is %Zd\n", it->second.Z);
  }
  for (c_each(item, umap_mpz, map)) {
    gmp_printf("%Zd -> %Zd\n", item.ref->first.Z, item.ref->second.Z);
  }

  umap_mpz_drop(&map);
    
  return 0;
}
