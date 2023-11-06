put_indicator (const struct bin_str *ind)
{
    static bool first_run = true;
  
    if (first_run)
    {
        first_run = false;
    
        /* If the standard output is a controlling terminal, watch out
           for signals, so that the colors can be restored to the 
           default state if "ls" is suspended or interrupted.  */

        if (tcgetpgrp (STDOUT_FILENO) >= 0)
            signal_init ();

        prep_non_filename_text ();
    }

    if (ind->len > 0) 
    {
        fwrite (ind->string, ind->len, 1, stdout);
    }
}