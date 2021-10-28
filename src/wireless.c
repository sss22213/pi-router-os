#include "wireless.h"

void find_all_wireless_interface(struct _wireless_list *wireless_list)
{
    FILE *ptr_cmd = NULL;
    
    ptr_cmd = popen("ip a | awk '{print $2}' | grep wlan* | sed 's/://g'", "r");

    char buf[INTERFACE_NAME_LENGTH] = {0};

    /**
     * Maximum text number is limited by 100 character on every line.
     * Read data until file tail 
     */
    for (int line = 0; fgets(buf, INTERFACE_NAME_LENGTH, ptr_cmd)!=NULL; line++) {
        
    }
}