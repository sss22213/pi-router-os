#ifndef __WIRELESS_H__
#define __WIRELESS_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define INIT_WIRELESS_IFACE(WIRELESS_IFACE_NAME) \
          struct _wireless_iface (WIRELESS_IFACE_NAME) = {0, {0}, {0}, {0}, 0, wireless_stop, NULL}

#define INIT_WIRELESS_HEAD(WIRELESS_IFACE_LIST_NAME) \
          struct _wireless_list (WIRELESS_IFACE_LIST_NAME) = {NULL}

#define INTERFACE_NAME_LENGTH 10
#define IFACE_NUMBER 100
#define IFACE_INFO  1024

typedef enum {
    wireless_active,
    wireless_stop,
} WIRELESS_ACTIVE;

struct _wireless_iface_node {
    int iface;
    struct _node iface_node;
};

struct _wireless_iface_active_node {
    int iface;
    char mac_addr[17];
    char ip_addr[15];
    char broadcast[15];
    char hwaddr[17];
    int mask;
    WIRELESS_ACTIVE wirless_action;
    struct _node iface_node;
};

struct _wireless_list {
    struct _wireless_iface *wireless_list_head;
};

void find_all_wireless_iface(struct _queue*);
void find_all_wireless_action_iface(struct _queue*);

#endif