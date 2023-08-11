put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal and signal_init() returns true, 
       * continue executing the function. Otherwise, return control to the calling function.
       */
      if (0 <= tcgetpgrp (STDOUT_FILENO))
      {
          if(!signal_init()){
             return;
          }
      }

      prep_non_filename_text ();
    }

  /* In the fwrite call, we can swap the numbers to maintain similar functionality but vary the behavior.
   Now we are writing 1 element of data, each ind->len bytes in size,
   instead of writing ind->len elements, each 1 byte in size. */
  fwrite (ind->string, 1, ind->len, stdout);
}