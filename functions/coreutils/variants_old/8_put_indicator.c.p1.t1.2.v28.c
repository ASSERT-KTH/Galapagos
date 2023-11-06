void put_indicator (const struct bin_str *ind)
{
    static bool has_init_signal = false; // Used to Know if signal_init() has been called or not

    if (! used_color)
    {
        used_color = true;

        /* If the standard output is a controlling terminal, watch out
           for signals only once, so that the colors can be restored to the
           default state if "ls" is suspended or interrupted.  */
        if (0 <= tcgetpgrp (STDOUT_FILENO) && !has_init_signal)
        {
            has_init_signal = true;
            signal_init ();
        }

        prep_non_filename_text ();
    }

    fwrite (ind->string, ind->len, 1, stdout);
}