#include <stdio.h>
#include "list.h"
#include "queue.h"
#include "tree.h"

struct _test {
    int val;
    struct _node node;
};

struct my_rb_tree_node {
    int val;
    struct _rb_leaf_node rb_leaf_node;
};

struct _leaf_and_lift_node {
    struct _rb_leaf_node *rb_leaf_node;
    struct _node list_node;
};

void bfs(struct _rb_root_node *rb_root_node, struct _queue *ptr_result)
{
    INIT_QUEUE(queue1, list1);
    int queue_size = 0;
    struct _rb_leaf_node *rb_tmp_node = rb_root_node->ptr_root_node;

    struct _leaf_and_lift_node *new_leaf_and_lift_node = \
                (struct _leaf_and_lift_node*)calloc(1, sizeof(struct _leaf_and_lift_node));
                
    new_leaf_and_lift_node->rb_leaf_node = rb_tmp_node;

    queue_push(&queue1, &(new_leaf_and_lift_node->list_node));

    while (queue1.size != 0) {
        queue_size = queue1.size;
        while (queue_size-- != 0) {
            struct _node *rb_ptr_node = queue_pull(&queue1);

            queue_push(ptr_result, rb_ptr_node);

            if (CONTAINER_OF(rb_ptr_node, struct _leaf_and_lift_node, list_node)->rb_leaf_node->left != NULL) {
                new_leaf_and_lift_node = \
                    (struct _leaf_and_lift_node*)calloc(1, sizeof(struct _leaf_and_lift_node));
                new_leaf_and_lift_node->rb_leaf_node = CONTAINER_OF(rb_ptr_node, struct _leaf_and_lift_node, list_node)->rb_leaf_node->left;
                queue_push(&queue1, &(new_leaf_and_lift_node->list_node));
            }

            if (CONTAINER_OF(rb_ptr_node, struct _leaf_and_lift_node, list_node)->rb_leaf_node->right != NULL) {
                new_leaf_and_lift_node = \
                    (struct _leaf_and_lift_node*)calloc(1, sizeof(struct _leaf_and_lift_node));
                new_leaf_and_lift_node->rb_leaf_node = CONTAINER_OF(rb_ptr_node, struct _leaf_and_lift_node, list_node)->rb_leaf_node->right;
                queue_push(&queue1, &(new_leaf_and_lift_node->list_node));
            }
        }
    }
}
bool cmp_rb_tree(struct _rb_leaf_node *rb_leaf_node_1, struct _rb_leaf_node *rb_leaf_node_2)
{
    int a_value = CONTAINER_OF(rb_leaf_node_1, struct my_rb_tree_node, rb_leaf_node)->val;
    int b_value = CONTAINER_OF(rb_leaf_node_2, struct my_rb_tree_node, rb_leaf_node)->val;
    if (a_value > b_value) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    INIT_ROOT(root1);
    INIT_QUEUE(queue_result, list2);
    INIT_QUEUE(queue_result2, list3);
    struct _node *ptr_node = NULL;
    struct my_rb_tree_node node1 = {6};
    struct my_rb_tree_node node2 = {2};
    struct my_rb_tree_node node3 = {11};
    struct my_rb_tree_node node4 = {1};
    struct my_rb_tree_node node5 = {8};
    struct my_rb_tree_node node6 = {15};
    struct my_rb_tree_node node7 = {9};
    struct my_rb_tree_node node8 = {10};
    struct _rb_leaf_node *search_node = NULL;
	struct _rb_leaf_node ptr_search_result;
    struct _rb_leaf_node *ptr_leaf_and_lift_node = NULL;
    root1.ptr_root_node = &(node1.rb_leaf_node);
    tree_insert_leaf(&root1, cmp_rb_tree, &(node2.rb_leaf_node));
    tree_insert_leaf(&root1, cmp_rb_tree, &(node3.rb_leaf_node));
    tree_insert_leaf(&root1, cmp_rb_tree, &(node4.rb_leaf_node));
    tree_insert_leaf(&root1, cmp_rb_tree, &(node5.rb_leaf_node));
    tree_insert_leaf(&root1, cmp_rb_tree, &(node6.rb_leaf_node));
    tree_insert_leaf(&root1, cmp_rb_tree, &(node7.rb_leaf_node));
    tree_insert_leaf(&root1, cmp_rb_tree, &(node8.rb_leaf_node));
    
    bfs(&root1, &queue_result);

	
    QUEUE_FOR_EACH(ptr_node, &queue_result) {
        struct _rb_leaf_node *ptr_leaf_and_lift_node = \
            CONTAINER_OF(ptr_node, struct _leaf_and_lift_node, list_node)->rb_leaf_node;

        printf("%d\n", CONTAINER_OF(ptr_leaf_and_lift_node, struct my_rb_tree_node, rb_leaf_node)->val);
    }
	
    
    printf("----------\n\n");

    tree_remove_leaf(&root1, cmp_rb_tree, &(node1.rb_leaf_node));

    bfs(&root1, &queue_result2);
    
    ptr_node = NULL;
    QUEUE_FOR_EACH(ptr_node, &queue_result2) {
        ptr_leaf_and_lift_node = \
            CONTAINER_OF(ptr_node, struct _leaf_and_lift_node, list_node)->rb_leaf_node;

        printf("%d\n", CONTAINER_OF(ptr_leaf_and_lift_node, struct my_rb_tree_node, rb_leaf_node)->val);
    }
    

    printf("----------\n\n");

    tree_search_leaf(&root1, cmp_rb_tree, &(node7.rb_leaf_node), &ptr_search_result);
    
    printf("%d\n", CONTAINER_OF(&ptr_search_result, struct my_rb_tree_node, rb_leaf_node)->val);

    return 0;
}