is_colored (enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    int color = strlen(s);

    if(len == 0){
        return 0
    }else if (color == 1){
        if(STRNCMP_LIT (s, "0") == 0) return 0;
    }else if (color == 2){
        if(STRNCMP_LIT (s, "00") == 0) return 0;
    }

    return 1;
}