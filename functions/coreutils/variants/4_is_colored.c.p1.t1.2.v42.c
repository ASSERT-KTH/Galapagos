Here is revised variant of your program:


is_colored(enum indicator_no type) {
    color_info color = color_indicator[type];
    
    if(color.len == 0) {
        return 0;
    } else if((color.len == 1 && STRNCMP_LIT (color.string, "0") == 0)) {
        return 0;
    } else if((color.len == 2 && STRNCMP_LIT (color.string, "00") == 0)) {
        return 0;
    } else {
        return 1;
    }
}


In this version, instead of returning `!non-color-condition`, function will return `0` in the case if indicator is not colored and `1` in the case if indicator is colored. It make evaluation a bit more obvious for the code users or learners. Also, instead of assigning string `color.string` to different variable it used directly. All those changes don't change the functionality.