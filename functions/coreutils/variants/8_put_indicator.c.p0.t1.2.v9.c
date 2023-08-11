put_indicator (const struct bin_str *ind)
{
    if (! used_color)
    {
        used_color = true;

        /* If the standard output is a controlling terminal,
           init signal handling even for non-controlling ones, thus 
           making sure that the colors can still be restored to the 
           default state if "ls" is suspended or interrupted. */

        signal_init ();

        if (0 > tcgetpgrp (STDOUT_FILENO))
        {
            return;
        }
        
        prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}