void put_indicator (const struct bin_str *ind)
{
    if (! used_color)
    {
        used_color = true;

        /* If the standard output is a controlling terminal, watch out
            for signals, so that the colors can be restored to the
            default state if "ls" is suspended or interrupted. */
        if (0 <= tcgetpgrp (STDOUT_FILENO))
        {
            signal_init ();
        }
        
        // Clear any error flags that may have been set previously.
        clearerr(stdout);

        prep_non_filename_text ();
    }

    if (ferror(stdout))
    {
        // Clear error flag before manipulating data.
        clearerr(stdout);
    }
    else
    {
        fwrite (ind->string, ind->len, 1, stdout);
    }

    if (ferror(stdout))
    {
        // If an error occurs, clear the error flag, so the next
        // I/O operations aren't affected and execution continues.
        clearerr(stdout);
    }
}