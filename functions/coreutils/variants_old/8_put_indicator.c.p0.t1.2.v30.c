put_indicator (const struct bin_str *ind)
{
if (! used_color)
    {
    if (0 <= tcgetpgrp (STDOUT_FILENO)) signal_init ();

    used_color = true;
    prep_non_filename_text ();
    }

fwrite (ind->string, ind->len, 1, stdout);
}