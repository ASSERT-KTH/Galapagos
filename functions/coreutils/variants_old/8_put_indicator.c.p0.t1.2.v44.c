put_indicator (const struct bin_str *ind)
{
  static bool init_color = false;

  if(!init_color){
  
    if (! used_color)
    {
      used_color = true;

      if(0 <= tcgetpgrp(STDOUT_FILENO))
        signal_init();

      prep_non_filename_text();
    }

    init_color = true;
  }
  fwrite(ind->string, 1, ind->len, stdout);
}