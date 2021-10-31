#include "wireless.h"

static inline int string_to_int(char *str)
{
    int result = 0;

    char *ptr_str = str;
    for (int str_idx = 0; *ptr_str!='\n' && *ptr_str!='\0' && str_idx < INTERFACE_NAME_LENGTH; str_idx++) {
        result = result * 10 + *ptr_str - '0';
        ptr_str++;
    }

    return result;
}

void find_iface_info(int iface_number)
{
    FILE *ptr_cmd_active_wlan_lookup = NULL;

    char *lookup_cmd = "ifconfig | grep -A1 wlan";

    char look_cmd_complete[strlen(lookup_cmd)+2];

    char iface[IFACE_INFO] = {0};

    sprintf(look_cmd_complete, "ifconfig | grep -A1 wlan%d", iface_number);

    ptr_cmd_active_wlan_lookup = popen(look_cmd_complete, "r");

    fgets(iface, IFACE_INFO, ptr_cmd_active_wlan_lookup);

    

}

void find_all_wireless_action_iface(struct _queue *iface_queue)
{
    FILE *ptr_cmd_active_wlan_lookup = NULL;

    char iface[IFACE_INFO] = {0};
    memset(iface, 0, sizeof(iface));

    char *ptr_iface_lookup_result = NULL;

    struct _wireless_iface_active_node *wireless_iface_active_node = NULL;
        
    ptr_cmd_active_wlan_lookup = popen("ifconfig | grep -A1 wlan*", "r");
    
    /*
    for (int idx = 0; idx < 1024; idx++) {
        printf("%c", iface[idx]);
    }
    */
    
    /*
    while (ptr_iface_lookup_result != NULL) {
        Write active wireless interface to buffer.
        wireless_iface_active_node = \
            (struct _wireless_iface_active_node*)calloc(1, sizeof(struct _wireless_iface_active_node));

        wireless_iface_active_node->iface = string_to_int(iface);
            
        queue_push(iface_queue, &(wireless_iface_active_node->iface_node));

        ptr_iface_lookup_result = fgets(iface, INTERFACE_NAME_LENGTH, ptr_cmd_active_wlan_lookup);
    }
    */
}

void find_all_wireless_iface(struct _queue *wireless_queue)
{
    FILE *ptr_cmd_wlan_lookup = NULL;

    struct _wireless_iface_node *wireless_iface_node = NULL;

    ptr_cmd_wlan_lookup = popen("ip a | awk '{print $2}' | grep wlan* | sed 's/://g' | sed 's/wlan//g'", "r");

    char iface[INTERFACE_NAME_LENGTH] = {0};

    char *ptr_iface_lookup_result = NULL;

    /**
     * Maximum text number is limited by 100 character on every line.
     * Read data until file tail 
     */
    for (int line = 0; fgets(iface, INTERFACE_NAME_LENGTH, ptr_cmd_wlan_lookup)!=NULL; line++) {
        wireless_iface_node = \
            (struct _wireless_iface_node*)calloc(1, sizeof(struct _wireless_iface_node));

        wireless_iface_node->iface = string_to_int(iface);
            
        queue_push(wireless_queue, &(wireless_iface_node->iface_node));
    }
}