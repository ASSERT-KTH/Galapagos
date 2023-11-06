put_indicator (const struct bin_str *ind)
{
  if (!used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, stand by
         for signals, making sure that the colors can be set back to
         the basic condition if "ls" command is halted or ruptured.  */

      if (STDOUT_FILENO <= tcgetpgrp (0))
        signal_init ();

      prep_non_filename_text ();
      
      /* This comment might not change functionality,
      but changes the behavior a bit... */
      
    }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout); //Ensure that there's immediate output
}