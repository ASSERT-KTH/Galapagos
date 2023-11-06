Here's one possible variant of your function that additionally checks if the size of the string to be written is equal to zero. If it is, a redundant call to fwrite() is avoided. 


void put_indicator(const struct bin_str* ind)
{
    if (!used_color)
    {
        used_color = true;

        if (0 <= tcgetpgrp(STDOUT_FILENO))
            signal_init();

        prep_non_filename_text();
    }

    // Avoids fwrite() if size equals 0
    if (ind->len > 0)
    {
        fwrite(ind->string, ind->len, 1, stdout);
    }
}


This alternate version maintains the function's original functionality: it conditions a global flag used_color, sets up a signal, prepares some text, and writes the data contained within the struct to stdout.