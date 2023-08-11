struct indicator {
    char *string;
    size_t len;
};

extern struct indicator color_indicator[];

enum indicator_no { green, red, blue };

int is_colored(enum indicator_no type) {
    if(color_indicator[type].len == 0)
        return 0;
    if(color_indicator[type].len == 1 && strncmp(color_indicator[type].string, "0", 1) == 0)
        return 0;
    if(color_indicator[type].len == 2 && strncmp(color_indicator[type].string, "00", 2) == 0)
        return 0;
        
    return 1;  
}