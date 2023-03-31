#include <stdio.h>
#include <string.h> // WORKAROUND: Needs string.h

typedef struct {
  int key;
  int value;
} pair_node;

static inline size_t pair_node_hash(pair_node *a)
{
  return a->key;
}

static inline int pair_node_equal(pair_node *a, pair_node *b)
{
  return a->key == b->key;
}

static inline void pair_node_free(pair_node *a)
{
  (void) a;
}

static inline pair_node pair_node_copy(pair_node *self)
{
  return (pair_node) { self->key, self->value };
}

#define T pair_node
#include <ctl/unordered_map.h>

int main(void)
{
  umap_pair_node map = umap_pair_node_init(pair_node_hash, pair_node_equal);
  umap_pair_node_insert(&map, (pair_node) { 17, 4585 });
  umap_pair_node_insert(&map, (pair_node) { 42, 4856 });
  umap_pair_node_insert(&map, (pair_node) { -9, 1452 });
  umap_pair_node_it it = umap_pair_node_find(&map, (pair_node) { 42, 0} );
  if (!umap_pair_node_it_done(&it) ) {
    printf("Value of 42 is %d\n", it.ref->value);
  }
  foreach(umap_pair_node, &map, it) {
    printf("%d -> %d\n", it.ref->key, it.ref->value);
  }
  umap_pair_node_free(&map);
  return 0;
}
