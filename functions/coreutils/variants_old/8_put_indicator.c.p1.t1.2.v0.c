Here's a program variant that preserves the original functionality, yet changes the behavior by checking the `len` variable for non-zero value before calling `fwrite`. This function won't output anything if `len` is zero.


void put_indicator(const struct bin_str *ind)
{
    if (! used_color)
    {
        used_color = true;

        /* If the standard output is a controlling terminal, watch out
           for signals, so that the colors can be restored to the
           default state if "ls" is suspended or interrupted.  */

        if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();

        prep_non_filename_text();
    }

    if (ind->len != 0)
    {
        fwrite(ind->string, ind->len, 1, stdout);
    }
}


The behaviour here is changed because the program won't attempt to write to `stdout` if the length of the `ind->len` is zero, potentially saving system resources by skipping an unnecessary function call on every control loop.