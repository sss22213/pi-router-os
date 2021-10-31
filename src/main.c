#include <stdio.h>
#include "pi_uci.h"
#include "list.h"
#include "queue.h"
#include "wireless.h"

int main()
{
	/* All wireless action 
	INIT_QUEUE(iface_active_queue, iface_active_list);
	find_all_wireless_iface(&iface_active_queue);
	struct _node *ptr_node;
	QUEUE_FOR_EACH(ptr_node, &iface_active_queue) {
		printf("%d\n", CONTAINER_OF(ptr_node, struct _wireless_iface_node, iface_node)->iface);
	}
	*/

	/*
	INIT_QUEUE(iface_active_queue, iface_active_list);
	find_all_wireless_action_iface(&iface_active_queue);
	*/

	find_iface_info(2);
	
	return 0;
}
