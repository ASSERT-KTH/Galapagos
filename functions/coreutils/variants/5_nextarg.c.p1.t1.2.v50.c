bool nextarg (char const *str)
{
    if (*args == nullptr){
        return false;
    }
     
    if(STREQ (*args, str)){
        args++;
        return true;
    }
    
    return false;
}