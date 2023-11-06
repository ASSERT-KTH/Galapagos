bool is_colored (enum indicator_no type)
{ 
    if(color_indicator[type].len == 0) return false;
    if (color_indicator[type].len == 1 && strstr(color_indicator[type].string, "0") != NULL) 
        return false;
    if (color_indicator[type].len == 2 && strstr(color_indicator[type].string, "00") != NULL) 
        return false;   
    return true;  
}