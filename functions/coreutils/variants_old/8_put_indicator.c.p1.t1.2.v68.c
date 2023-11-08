void put_indicator (const struct bin_str *ind)
{
    static int color_initialized = 0;
    if (! color_initialized)
    {    
        color_initialized = 1;

        /* If the standard output is a controlling terminal, watch out
            for signals, so that the colors can be restored to the
            default state if "ls" is suspended or interrupted.  */

        if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();

        prep_non_filename_text ();
    }
        
    fwrite (ind->string, ind->len, 1, stdout);
}