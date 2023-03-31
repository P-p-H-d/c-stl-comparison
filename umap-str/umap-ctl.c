#include <stdio.h>
#include <string.h> // WORKAROUND: Needs string.h
#include <ctl/string.h>

typedef struct {
  str key;
  str value;
} pair_node;

static inline size_t pair_node_hash(pair_node *a)
{
  size_t h = 0;
  for(size_t i = 0; i < str_size(&a->key); i++) {
    h = h*33 + *str_at(&a->key, i);
  }
  return h;
}

static inline int pair_node_equal(pair_node *a, pair_node *b)
{
  return str_equal(&a->key, &b->key); // WORKAROUND: Not present in documentation
}

static inline void pair_node_free(pair_node *a)
{
  str_free(&a->key);
  str_free(&a->value);
}

static inline pair_node pair_node_copy(pair_node *self)
{
  return (pair_node) { str_copy(&self->key), str_copy(&self->value) };
}

#define T pair_node
#include <ctl/unordered_map.h>

int main(void)
{
  umap_pair_node map = umap_pair_node_init(pair_node_hash, pair_node_equal);
  str key, value;
  key = str_init("Hello");
  value = str_init("LIB");
  umap_pair_node_insert(&map, (pair_node) { key, value });
  key = str_init("Welcome"); // WORKAROUND: Need a new init for each string 
  value = str_init("Program");
  umap_pair_node_insert(&map, (pair_node) { key, value });
  key = str_init("Sincerely");
  value = str_init("Your map");
  umap_pair_node_insert(&map, (pair_node) { key, value });
  key = str_init("Welcome");
  value = str_init("");
  umap_pair_node_it it = umap_pair_node_find(&map, (pair_node) { key, value} );
  if (!umap_pair_node_it_done(&it) ) {
    printf("Value of Welcome is %s\n", str_c_str(&it.ref->value) ); // WORKAROUND: Not present in documentation
  }
  foreach(umap_pair_node, &map, it) {
    printf("%s -> %s\n", str_c_str(&it.ref->key), str_c_str(&it.ref->value)) ;
  }
  str_free(&key);
  str_free(&value);
  umap_pair_node_free(&map);
  return 0;
}
