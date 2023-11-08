put_indicator (const struct bin_str *ind)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    if (! used_color)
    {
        used_color = true;

        /* If the standard output is a controlling terminal, watch out
                for signals, so that the colors can be restored to the
                default state if "ls" is suspended or interrupted.  */

        if (STDOUT_FILENO <= tcgetpgrp (0))
        {
            signal_init ();
        }

        prep_non_filename_text ();
    }

    fwrite (ind->string, 1, ind->len, stdout);
}