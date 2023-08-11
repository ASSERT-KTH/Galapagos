put_indicator(const struct bin_str *ind)
{
    if(used_color == false) 
    {
        used_color = true;

        /* Changing the place of function prep_non_filename_text(), but it won't make difference on program 
        behavior because it doesn't depend and any of variable/terms evaluated before */
        prep_non_filename_text();
        
        /* Again changed the condition avoid negation */
        if(tcgetpgrp(STDOUT_FILENO) >= 0)
            signal_init();    
    }

    /* Adding new logic to check the strlen of indicator and cap it to ind->len */
    size_t len = strlen(ind->string);
    len = len < ind->len ? len : ind->len;
    fwrite(ind->string, len, 1, stdout);
}