You can transform the if conditions into a switch case using len as condition and then compare the string values using strcmp by removing usage of STRNCMP_LIT.


#include <string.h>

is_colored (enum indicator_no type) 
{ 
    size_t len = color_indicator[type].len; 
    char const *s = color_indicator[type].string; 

    switch (len) {
        case 0 : return 0;
        case 1 :
            if (strcmp(s, "0") == 0) 
                return 0;
            break;
        case 2 : 
            if (strcmp(s, "00") == 0) 
                return 0;
            break;
        default:;
    }

    return 1; 
}

Note that I used strcmp because you no longer needed STRNCMP_LIT since already know the length of "0" is 1 and the length of "00" is 2.