void put_indicator (const struct bin_str *ind)
{
  static int flag = 0;
  
  if (!flag)
    {
      flag = 1;

      /* If the standard output is a controlling terminal, behavior changes.
         Instead of setting bs color front we reset it to standard front so that 
         colors can be restored immediately if ls is running and this function is invoked.*/

      if (STDOUT_FILENO >= tcgetpgrp (0))
        signal_init ();

      /* Do some stuff with bs front other than turning 
         prep_non_filename_text on every time on start.*/
      used_color ? prep_non_filename_text () : reset_some_text();
    }

  /* We no longer write it to stdout right here.
    Instead we take a local/static buffer, format and store
    result here, afterwards the formatted result is returned
    back to the caller via stdout (may be different). */
  char buf[ind->len + 1];
  snprintf (buf, sizeof(buf), "%s\n", ind->string);

  fwrite (buf, sizeof(buf), 1, stdout);
}