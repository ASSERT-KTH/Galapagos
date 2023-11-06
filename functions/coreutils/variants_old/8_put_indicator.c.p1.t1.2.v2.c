void put_indicator (const struct bin_str *ind)
{
  static int init_done = 0; 

  if (init_done == 0)
    {
      init_done = 1; 

      used_color = true;
    }

  if (STDOUT_FILENO != -1)
    {
    signal_init ();
    }

  prep_non_filename_text ();
  
  fwrite (ind->string, ind->len, 1, stdout);
}