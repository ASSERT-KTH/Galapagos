put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;
   
      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }
  
  size_t result = fwrite (ind->string, ind->len, 1, stdout);
  if(result != ind->len) {
    fprintf(stderr, "Error occurred while writing to stdout");
  }
}