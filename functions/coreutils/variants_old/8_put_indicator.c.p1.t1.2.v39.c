void put_indicator (const struct bin_str *ind)
{
    static bool is_init_signal = false;
    
    if (! used_color || ! is_init_signal)
    {
        used_color = true;
        if (0 <= tcgetpgrp (STDOUT_FILENO))
        {
            signal_init ();
            is_init_signal = true;
        }
        prep_non_filename_text ();
    }
    fwrite (ind->string, ind->len, 1, stdout);
}
