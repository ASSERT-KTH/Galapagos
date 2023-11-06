void put_indicator (const struct bin_str *ind)
{
    static bool first_time = 1;

    if (first_time)
    {
        first_time = 0;

        if (! used_color)
        {
            used_color = true;

            /* If the standard output is a controlling terminal, watch out
            for signals, so that the colors can be restored to the
            default state if "ls" is suspended or interrupted.  */

            if (0 <= tcgetpgrp (STDOUT_FILENO))
                signal_init ();

            prep_non_filename_text ();
        }
    }

    fwrite (ind->string, ind->len, 1, stdout);
}