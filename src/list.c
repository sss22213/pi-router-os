#include "list.h"

static inline void _list_add(struct _list *list, struct _node *target_node, struct _node *node)
{   
    struct _node *ptr_node = NULL;
    struct _node *tmp = NULL;

    LIST_FOR_EACH(ptr_node, list) {
        if (ptr_node == target_node) {
            tmp = ptr_node->next;
            ptr_node->next = node;
            node->next = tmp;
            break;
        }
    }
}

static inline struct _node *_list_tail_node(struct _list *list)
{
    struct _node *ptr_node = NULL;
    LIST_FOR_EACH(ptr_node, list) {
        if (ptr_node->next == NULL) {
            return ptr_node;
        }
    }
    
    return NULL;
}

void list_push_back(struct _list *list, struct _node *node)
{
    _list_add(list, _list_tail_node(list), node);
}

void _list_remove(struct _list *list, struct _node *target_node, struct _node *node)
{
    struct _node *ptr_node = NULL;
    struct _node *tmp = NULL;

    LIST_FOR_EACH(ptr_node, list) {
        if (ptr_node->next == target_node) {
            tmp = ptr_node->next->next;
            ptr_node->next = tmp;
            break;
        }
    }
}