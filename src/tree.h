#ifndef __TREE_H__
#define __TREE_H__
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include "queue.h"

#define INIT_LEAF(LEAF_NAME) \
        struct _rb_leaf_node (LEAF_NAME) = {RED, NULL, NULL, NULL}

#define INIT_ROOT(ROOT_NAME) \
            struct _rb_root_node (ROOT_NAME) = {NULL, NULL};

typedef enum {
    RED,
    BLACK,
} RB_TREE_COLOR;

struct _rb_leaf_node {
    int color;
    struct _rb_leaf_node *parent;
    struct _rb_leaf_node *right;
    struct _rb_leaf_node *left;
};

struct _rb_root_node {
    struct _rb_leaf_node *ptr_root_node;
    struct _rb_leaf_node *ptr_nul_node;
};

void tree_insert_leaf(struct _rb_root_node*, bool (*)(struct _rb_leaf_node*, struct _rb_leaf_node*), struct _rb_leaf_node*);
void tree_remove_leaf(struct _rb_root_node*, bool (*)(struct _rb_leaf_node*, struct _rb_leaf_node*), struct _rb_leaf_node*);
void tree_search_leaf(struct _rb_root_node*, bool (*)(struct _rb_leaf_node*, struct _rb_leaf_node*), \
                            struct _rb_leaf_node*, struct _rb_leaf_node*);
void _bfs(struct _rb_root_node*);
void _dfs(struct _rb_root_node*);

#endif