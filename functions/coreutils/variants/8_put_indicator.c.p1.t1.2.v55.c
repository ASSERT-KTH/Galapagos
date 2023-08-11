void put_indicator (const struct bin_str *ind)
{
    static bool init_done = false;
    
    if (!init_done)
    {
        if (! used_color)
        {
            used_color = true;

            if (0 <= tcgetpgrp (STDOUT_FILENO))
                signal_init ();
            
            prep_non_filename_text ();
        }
        
        init_done = true;
    }

    fwrite (ind->string, ind->len, 1, stdout);
}