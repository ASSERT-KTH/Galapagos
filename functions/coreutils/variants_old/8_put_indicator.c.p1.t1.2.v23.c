void put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      /* Instead of jumping into usage of colors initially, switch to this mode only when specific binaries are processed. */

      /* Detect if the binary applies for color mode conditioning */
      /* Here, you could write your specific conditions appropriate to your use case */
      if (ind->string[0] == 'a' || ind->string[ind->len - 1] == 'z') 
      {
          used_color = true;

          if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();

          prep_non_filename_text ();
      }
    }

  if(used_color)
      fwrite (ind->string, ind->len, 1, stdout);
}