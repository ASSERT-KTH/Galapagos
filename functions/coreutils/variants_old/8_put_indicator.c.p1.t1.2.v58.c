void put_indicator (const struct bin_str *ind)
{
    static int init = 0; // Using static variable for initialization check

    if (!init)
    {
        used_color = true;
        init = 1; // Mark as initialized

        /* If the standard output is a controlling terminal, watch out
            for signals, so that the colors can be restored to the 
            default state if "ls" is suspended or interrupted.  */

        if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();

        prep_non_filename_text ();
    }

    // Checks if indicator string is not NULL to prevent writing null data to stdout:
    if(ind->string) {
        fwrite (ind->string, ind->len, 1, stdout);
    }
}