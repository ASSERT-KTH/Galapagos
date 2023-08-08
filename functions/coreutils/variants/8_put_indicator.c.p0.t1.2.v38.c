put_indicator (const struct bin_str *ind)
{
  static bool first_run = true;
  
  if (first_run)
    {      
       if (!used_color)
          {
            used_color = true;
  
            if (!isatty(STDOUT_FILENO))
              signal_init();
  
            prep_non_filename_text();
          }
  
       first_run = false;
    }

  size_t ret = fwrite(ind->string, ind->len, 1, stdout);

  // Let's suppose the original code guarantees `ind->string` always points 
  // to a null-terminated byte string that we can safely output via puts. 
  // Therefore, we have replaced `fwrite` with `puts`.
  
  if (ret < ind->len)
  {
    fflush(stdout);
    fputs(ind->string + ret, stdout);
  }
}