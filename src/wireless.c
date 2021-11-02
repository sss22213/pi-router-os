#include "wireless.h"

/* Command for lookup iface information */
#define IFACE_LOOKUP_HWADDR_CMD "ifconfig | grep -A1 wlan%d | grep HWaddr | awk '{print $5}'"
#define IFACE_LOOKUP_IPV4_CMD "ifconfig | grep -A1 wlan%d | grep inet | awk '{print $2}' | sed 's/addr://g'"
#define IFACE_LOOKUP_BCAST_CMD "ifconfig | grep -A1 wlan%d | grep Bcast | awk '{print $3}' | sed 's/Bcast://g'"
#define IFACE_LOOKUP_MASK_CMD "ifconfig | grep -A1 wlan%d | grep Mask | awk '{print $4}' | sed 's/Mask://g'"
#define IFACE_LOOKUP_ACTIVE_IFACE_CMD "ifconfig | grep wlan* | awk '{print $1}' | sed 's/wlan//g'"
#define IFACE_LOOKUP_SUPPORT_FREQ  "iwlist wlan%d channel | awk '{print $4}' | grep '[[:digit:]]'"
#define IFACE_LOOKUP_SUPPORT_CHANNEL  "iwlist wlan%d channel | awk '{print $2}' | grep '[[:digit:]]' | sed '1d;$d'"

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

static inline struct _wireless_iface_iwlist_node *_find_support_freq_channel(int iface_number)
{
    FILE *ptr_cmd_active_wlan_lookup = NULL;

    char look_cmd[IFACE_INFO] = {0};
    memset(look_cmd, 0, sizeof(look_cmd));

    char iface[IFACE_INFO] = {0};
    memset(iface, 0, sizeof(iface));

    struct _wireless_iface_active_node *wireless_iface_active_node = \
        (struct _wireless_iface_active_node*)calloc(1, sizeof(struct _wireless_iface_active_node));

    

    


}

static inline struct _wireless_iface_active_node *find_iface_info(int iface_number)
{
    FILE *ptr_cmd_active_wlan_lookup = NULL;

    char look_cmd[IFACE_INFO] = {0};
    memset(look_cmd, 0, sizeof(look_cmd));

    char iface[IFACE_INFO] = {0};
    memset(iface, 0, sizeof(iface));

    struct _wireless_iface_active_node *wireless_iface_active_node = \
        (struct _wireless_iface_active_node*)calloc(1, sizeof(struct _wireless_iface_active_node));

    wireless_iface_active_node->iface = iface_number;

    /* Hardware(MAC) address */
    sprintf(look_cmd, IFACE_LOOKUP_HWADDR_CMD, iface_number);

    ptr_cmd_active_wlan_lookup = popen(look_cmd, "r");

    fgets(iface, IFACE_INFO, ptr_cmd_active_wlan_lookup);

    strcpy(wireless_iface_active_node->hwaddr, iface);

    /* Broadcast */
    memset(look_cmd, 0, sizeof(look_cmd));
    memset(iface, 0, sizeof(iface));

    sprintf(look_cmd, IFACE_LOOKUP_BCAST_CMD, iface_number);

    ptr_cmd_active_wlan_lookup = popen(look_cmd, "r");

    fgets(iface, IFACE_INFO, ptr_cmd_active_wlan_lookup);

    strcpy(wireless_iface_active_node->broadcast, iface);

    /* IPV4 */
    memset(look_cmd, 0, sizeof(look_cmd));
    memset(iface, 0, sizeof(iface));

    sprintf(look_cmd, IFACE_LOOKUP_IPV4_CMD, iface_number);

    ptr_cmd_active_wlan_lookup = popen(look_cmd, "r");

    fgets(iface, IFACE_INFO, ptr_cmd_active_wlan_lookup);

    strcpy(wireless_iface_active_node->ip_addr, iface);

    return wireless_iface_active_node;
    
}

void find_all_wireless_action_iface(struct _queue *iface_queue)
{
    FILE *ptr_cmd_active_wlan_lookup = NULL;

    char iface[IFACE_INFO] = {0};
    memset(iface, 0, sizeof(iface));
        
    ptr_cmd_active_wlan_lookup = popen(IFACE_LOOKUP_ACTIVE_IFACE_CMD, "r");

    /* Find all of active interface and information*/
    while (fgets(iface, IFACE_INFO, ptr_cmd_active_wlan_lookup)!=NULL) {
        queue_push(iface_queue, &(find_iface_info(string_to_int(iface))->iface_node));
    }
}

void find_all_wireless_iface(struct _queue *wireless_queue)
{
    FILE *ptr_cmd_wlan_lookup = NULL;

    struct _wireless_iface_node *wireless_iface_node = NULL;

    ptr_cmd_wlan_lookup = popen("ip a | awk '{print $2}' | grep wlan* | sed 's/://g' | sed 's/wlan//g'", "r");

    char iface[INTERFACE_NAME_LENGTH] = {0};

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