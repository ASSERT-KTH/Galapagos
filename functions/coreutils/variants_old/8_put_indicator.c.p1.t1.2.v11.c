Here you can find a variant of the function that also includes functionality for outputting to a file rather than just stdout. Importantly, this maintains the original functionality as stdout is the default.


#include <stdio.h>
#include <stdbool.h>
#include <signal.h>
#include <unistd.h>

struct bin_str { 
    char *string; 
    size_t len; 
}; 

bool used_color = false;

void signal_init(){}
void prep_non_filename_text(){}

void put_indicator (const struct bin_str *ind, FILE* output = stdout)
{
    if (! used_color)
    {
        used_color = true;

        /* If the standard output is a controlling terminal, watch out
            for signals, so that the colors can be restored to the
            default state if "ls" is suspended or interrupted.  */

        if (0 <= tcgetpgrp (fileno(output)))
            signal_init ();

        prep_non_filename_text ();
    }

    fwrite (ind->string, ind->len, 1, output);
}

Importantly, to use the function in the exact same way as before, you can just call `put_indicator(ind)`, which will output to stdout by default. To output to a specific file, use `put_indicator(ind, my_file)`.