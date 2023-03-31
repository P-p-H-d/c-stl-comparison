#include <stdio.h>
#include <gmp.h>
#include <string.h> // WORKAROUND: Needs string.h
#include <ctl/string.h>

typedef struct {
  mpz_t key;
  mpz_t value;
} pair_node;

static inline size_t pair_node_hash(pair_node *z)
{
  mp_size_t  n = z->key->_mp_size;
  mp_limb_t *p = z->key->_mp_d;
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

static inline int pair_node_equal(pair_node *a, pair_node *b)
{
  return mpz_cmp(a->key, b->key) == 0;
}

static inline void pair_node_free(pair_node *a)
{
  mpz_clear(a->key);
  mpz_clear(a->value);
}

static inline pair_node pair_node_copy(pair_node *self)
{
  pair_node ret;
  mpz_init_set(ret.key, self->key);
  mpz_init_set(ret.value, self->value);
  return ret;
}

#define T pair_node
#include <ctl/unordered_map.h>

int main(void)
{
  umap_pair_node map = umap_pair_node_init(pair_node_hash, pair_node_equal);
  pair_node node;
  //M_LET( ( map, ((17), (4585)), ((42), (4856)), ((-9),(1452)) ), umap_mpz_t) {
  
  mpz_init_set_si(node.key, 17);
  mpz_init_set_si(node.value, 4585);
  umap_pair_node_insert(&map, node);
  mpz_init_set_si(node.key, 42); // WORKAROUND : needs a new init for each push
  mpz_init_set_si(node.value, 4856);
  umap_pair_node_insert(&map, node);
  mpz_init_set_si(node.key, -9); // WORKAROUND : needs a new init for each push
  mpz_init_set_si(node.value, 1452);
  umap_pair_node_insert(&map, node);
  mpz_init_set_si(node.key, 42); // WORKAROUND : needs a new init for each push
  mpz_init_set_si(node.value, 0);
  umap_pair_node_it it = umap_pair_node_find(&map, node);
  if (!umap_pair_node_it_done(&it) ) {
    gmp_printf("Value of 42 is %Zd\n", it.ref->value);
  }
  foreach(umap_pair_node, &map, it) {
    gmp_printf("%Zd -> %Zd\n", it.ref->key, it.ref->value);
  }
  mpz_clear(node.key);
  mpz_clear(node.value);
  umap_pair_node_free(&map);
  return 0;
}
