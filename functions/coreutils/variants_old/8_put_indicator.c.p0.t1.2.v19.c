put_indicator (const struct bin_str *ind)
{
    static bool is_started_once = false;

    if (!used_color || !is_started_once)
    {
        used_color = true;
        is_started_once = true;

        /* If the standard output is a controlling terminal, watch out
        for signals, so that the colors can be restored to the
        default state if "ls" is suspended or interrupted.  */

        if (tcgetpgrp (STDOUT_FILENO) >= 0)
            signal_init ();

        prep_non_filename_text ();
    }

    fwrite(ind->string, ind->len, 1, stdout);
    fflush(stdout);
}