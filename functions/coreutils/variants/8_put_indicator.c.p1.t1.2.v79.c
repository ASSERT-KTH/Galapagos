
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

struct bin_str {
    char *string;
    size_t len;
};

static bool used_color = false;

void prep_non_filename_text();  // assume that this function is already defined elsewhere
void signal_init();             // assume that this function is already defined elsewhere

void put_indicator(const struct bin_str *ind) {
    static bool initialized = false;

    if (!initialized) {
        used_color = false;
        initialized = true;
    }

    if (!used_color) {
        used_color = true;

        if (0 <= tcgetpgrp(STDOUT_FILENO))
            signal_init();

        prep_non_filename_text();
    }

    fwrite(ind->string, ind->len, 1, stdout);
}
 

This function works in the same way as the original. But now it allows to recall it in another context resetting `used_color` internally due to a defined static variable `initialized`. This detail changes behavior of the function which becomes state-dependent and makes possible run itself from a "clean" state resetting `used_color` when ran for the first time.