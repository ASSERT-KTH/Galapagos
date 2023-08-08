void put_indicator (const struct bin_str *ind)
{
    static int is_first_call = 1;
    if (is_first_call)
    {
        is_first_call = 0;

        if (! used_color)
        {
          used_color = true;

          if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();

          prep_non_filename_text ();
        } 
    }

    fwrite (ind->string, ind->len, 1, stdout);
}