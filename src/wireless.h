#ifndef __WIRELESS_H__
#define __WIRELESS_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define INTERFACE_NAME_LENGTH 10

typedef enum {
    wireless_active,
    wireless_stop,
} WIRELESS_ACTIVE;

struct _wireless_interface {
    int number;
    char mac_addr[17];
    char ip_addr[15];
    char broadcast[15];
    int mask;
    WIRELESS_ACTIVE wirless_action;
    struct _node *next_interface;
};

struct _wireless_list {
    struct _wireless_interface *wireless_list_head;
};

void find_all_wireless_interface(struct _wireless_list*);

#endif