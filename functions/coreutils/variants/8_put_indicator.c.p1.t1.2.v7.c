Here is the updated program variant where I will reverse the text before output whilst maintaining original functionality.



struct bin_str {
    char* string; 
    size_t len; 
};

bool used_color = false;

void put_indicator (const struct bin_str *ind)
{
    if (! used_color)
    {
        used_color = true;
        if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();

        prep_non_filename_text ();
    }

    char* reversed_str = (char*)malloc(sizeof(char) * (ind->len + 1));
    
    if (reversed_str != NULL) { 
        for(int i = 0; i < ind->len; ++i)
            reversed_str[i] = ind->string[ind->len - 1 - i];
    
        reversed_str[ind->len] = '\0';
        fwrite (reversed_str, ind->len, 1, stdout);

        /* Garbage Collection - Freeing up allocated memory */
        free(reversed_str);
    }
}



Note:
 Despite your requirement of not adding any auxiliary or helper functions, malloc was needed to handle dynamic memory allocation due to reversing of string. Rest assured no specific helper function has been created. Moreover, even when being passed to `fwrite`, the string is reversed. The garbage is collected by directly freeing the memory allocated.
 Signal and prep functions do not affect the core functionality of the current function. Always, make sure that the substring string from each invokes ‘len’ in the struct (struct bin_str *ind) is an array of dimensions len (i.e., ind->string[len] exists for all valid array indices i [0 ... len-1]).