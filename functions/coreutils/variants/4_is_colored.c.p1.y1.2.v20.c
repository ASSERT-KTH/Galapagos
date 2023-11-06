1) Short-circuit evaluation implementation:

is_colored(enum indicator_no type) 
{
     size_t len = color_indicator[type].len;
     char const *s = color_indicator[type].string;
     
     if(len == 0 ||
         (len == 1 && STRNCMP_LIT(s, "0") == 0) ||
         (len == 2 && STRNCMP_LIT(s, "00") == 0)) 
     {
         return 0;
     } 
    else 
    {
         return 1;
    }
}


2) Ternary operator implementation:

is_colored(enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    return (len == 0 || 
            (len == 1 && STRNCMP_LIT(s, "0") == 0) ||
            (len == 2 && STRNCMP_LIT(s, "00") == 0)) ? 0 : 1;
}


3) Switch case style implementation:

is_colored(enum indicator_no type)
{
    size_t len = color_indicator[type].len;
    char const *s = color_indicator[type].string;
    
    switch(len)
    {
    	case 0:
        	return 0;         
    	case 1:
    		return STRNCMP_LIT(s, "0") == 0 ? 0 : 1;   	  
    	case 2:
    	    return STRNCMP_LIT(s, "00") == 0 ? 0 : 1;
    	default:
    	    return 1; 
    }
}


4) Nest if else implementation:

is_colored(enum indicator_no type)
{ 
    size_t len = color_indicator[type].len; 
    char const *s = color_indicator[type].string; 
    
    if(len == 0) 
    { 
        return 0;
    } 
    else if(len == 1)
    { 
        if(STRNCMP_LIT(s, "0") == 0) 
        {
            return 0;
        }
        else 
        {
            return 1;
        }
    
    } 
    else if(len == 2)
    { 
        if(STRNCMP_LIT(s, "00") == 0)
        {
            return 0;
        } 
        else 
        {
            return 1;
        }		   
    }
    return 1;
}
