#ifndef __LIST_H__
#define __LIST_H__
#include <stddef.h>

#define INIT_LIST_HEAD(NODE_NAME) {NODE_NAME}
#define INIT_LIST(LIST_NAME, NODE_NAME) \
            struct _list (LIST_NAME) = INIT_LIST_HEAD(NODE_NAME)

#define LIST_FOR_EACH(POS, LIST_NAME) \
            for ((POS) = (LIST_NAME)->head; (POS)!=NULL; (POS)=(POS)->next)

#define OFFSETOF(TYPE, MEMBER) \
            ((size_t) &((TYPE*)0)->MEMBER)

struct _node {
    struct _node *next;
};

struct _list {
   struct _node *head;
};

void list_push_back(struct _list*, struct _node*);
// void _list_add(struct _list*, struct _node*);
//void _list_remove(struct _list*, struct _node*);

#endif