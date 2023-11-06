1. Using logical AND operator (`&&`) instead of logical OR operator (`||`)


is_colored(enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    
    return (len != 0
            && !(len == 1 && STRNCMP_LIT(s, "0") == 0)
            && !(len == 2 && STRNCMP_LIT(s, "00") == 0));
}


2. Without inline negations and with extra variable for clarity


is_colored(enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    
    int is_zero_esque = (len == 1 && STRNCMP_LIT(s, "0") == 0) 
        || (len == 2 && STRNCMP_LIT(s, "00") == 0);
        
    return len != 0 && !is_zero_esque;
}


3. Protect from value '255' 


is_colored(enum indicator_no type)
{
	size_t len;
	char const* s;

	if(type > 254)
		return 0;

	len = color_indicator[type].len;
	s = color_indicator[type].string;

	return !(len == 0 || (len == 1 && STRNCMP_LIT(s, "0") == 0) || (len == 2 && STRNCMP_LIT(s, "00") == 0));
}


4. More long but easier controlled version with separate returns


is_colored(enum indicator_no type)
{
	size_t len = color_indicator[type].len;
	char const* s = color_indicator[type].string;

	if (len == 0)
		return 0;
	elif (len == 1 && STRNCMP_LIT(s, "0") == 0)
		return 0;
	elif (len == 2 && STRNCMP_LIT(s, "00") == 0)
		return 0;
	else
        return 1;
}
