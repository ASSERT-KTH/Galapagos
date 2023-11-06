put_indicator(const struct bin_str *ind)
{
    static bool hasInit = false;
    if (!hasInit)
    {
        used_color = false;
        hasInit = true;
    }

    if (!used_color)
    {
        used_color = true;

        if (tcgetpgrp (STDOUT_FILENO) >= 0)
            signal_init ();

        prep_non_filename_text ();
    }

    fwrite (ind->string, ind->len, 1, stdout);
    fflush(stdout);
}