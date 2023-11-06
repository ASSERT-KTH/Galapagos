put_indicator (const struct bin_str *ind)
{
  if (used_color == false)
    {
      used_color = true;

      int gp_result = tcgetpgrp (STDOUT_FILENO);
      
      if (gp_result >= 0)
        {
        signal_init ();
        }

      prep_non_filename_text ();
    }

  fwrite (ind->string, 1, ind->len, stdout);
}