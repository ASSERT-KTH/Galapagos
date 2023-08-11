The following example code preserves the basic functionality of the original function, but introduces a different approach, to some extent. Here, instead of checking if used_color is not used every single time, it moves the fwrite() statement into the If clause. So, fwrite() would only happen the first time this function is called, when used_color is FALSE, after which, it would be switched to TRUE and fwrite() wouldn't be executed again. 


void put_indicator (const struct bin_str *ind)
{
  if (!used_color)
  {
    used_color = true;

    if (0 <= tcgetpgrp (STDOUT_FILENO))
      signal_init ();

    prep_non_filename_text ();
    fwrite (ind->string, ind->len, 1, stdout);
  }
}

Please note that the requested changes may have an impact on the target application if more than one fwrite is expected during the execution given this change prevents more than one execution of fwrite.

Please also remember that normally it's better to not create variants of existing functionality without assessing existing requirements first.