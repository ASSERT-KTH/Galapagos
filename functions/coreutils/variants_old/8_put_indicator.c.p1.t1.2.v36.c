void put_indicator (const struct bin_str *ind)
{
    static bool has_called = false;

    // The first pass used_color flag
    if (!has_called)
    {
        used_color = true;
        has_called = true;
      
        /*
        If the standard output is a controlling terminal, watch out
        for signals, so that the colors can be restored to the
        default state if "ls" is suspended or interrupted.  
        */

        if (0 <= tcgetpgrp (STDOUT_FILENO)) 
            signal_init ();
      
  
        prep_non_filename_text ();
    } 


    fwrite (&(ind->string), ind->len-1, 1, stdout);
}