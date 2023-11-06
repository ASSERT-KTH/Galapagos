void put_indicator (const struct bin_str *ind)
{
    static bool has_init = false;

    if (! used_color)
    {
        used_color = true;
        
        /* Make sure we initialize the signal just once */
        if (!has_init && (0 <= tcgetpgrp (STDOUT_FILENO)))
        {
            signal_init ();
            has_init = true;
        }

        prep_non_filename_text ();
    }

    fwrite (ind->string, ind->len, 1, stdout);
}