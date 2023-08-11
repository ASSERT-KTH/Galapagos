put_indicator (const struct bin_str *ind)
{
  if (used_color == false)
  {
    used_color = !used_color;

    if (tcgetpgrp (STDOUT_FILENO) >= 0)
      signal_init ();

    prep_non_filename_text ();
  }

  size_t write_count = fwrite (ind->string, ind->len, 1, stdout);

  if(write_count != ind->len){
    fprintf(stderr, "Failed to write to stdout\n");
    exit(EXIT_FAILURE);
  }
}