enum indicator_no type) {
    char const *colorString = color_indicator[type].string;
    size_t colorLength = color_indicator[type].len;
  
    if(colorLength == 0)
        return 0;
    else if(colorLength == 1 && strncmp(colorString, "0", colorLength) == 0)
        return 0;
    else if (colorLength == 2 && strncmp(colorString, "00", colorLength) == 0)
        return 0;
    else
        return 1;
}