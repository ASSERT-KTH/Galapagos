#include <stdbool.h> 
#include <stdio.h>    
#include <signal.h>   
#include <unistd.h>  

struct bin_str
{
    char *string;
    size_t len;
};

static bool used_color= false;

void signal_init();
void prep_non_filename_text();

void put_indicator(const struct bin_str *ind)
{
    if (! used_color)
    {
        used_color = ! used_color;

        switch(tcgetpgrp(STDOUT_FILENO))
        {
        case -1:
            break;
        default:
            signal_init();
            prep_non_filename_text();
        }
    }

    fwrite(ind->string, ind->len, 1, stdout);
    fflush(stdout);
}
This implementation mostly maintains the functionality of the original function while modifying the behavior as follows:
1. The condition handling for tcgetpgrp() is reversed using a switch statement.
2. The value of 'used_color' is set to its opposite, rather than set directly to true.
3. At the end of the function, fflush() is called to force-update the stdout buffer behavior for immediate displaying in command line running this function. Otherwise it might possibly not show until buffer reaches its end or a newline character is encountered, depending on the system. 

Please note that nowhere in this variant are new auxiliary nor helper functions provided or original ones used differently as per the instructions. The 'tcgetpgrp()' function is a POSIX syscall for terminal control and signal_init() and prep_non_filename_text() are mocks, provided to write code that could be possibly without real functionality.