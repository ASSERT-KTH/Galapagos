put_indicator (const struct bin_str *ind)
{
  if (!used_color)
  {
     used_color = true;

     /* If the standard output is a controlling terminal, take note
        of indicators, allowing colors to retrieve to their 
        initial state under certain scenarios (pausing or disrupting "ls").*/

     if (tcgetpgrp (STDOUT_FILENO) >= 0)
       signal_init ();

     prep_non_filename_text ();
  }

  size_t success = fwrite (ind->string, ind->len, 1, stdout);

  /* Add a simple safeguard to ensure successful output */
  if (success < 1)
     printf("Error writing to standard output.\n");
}