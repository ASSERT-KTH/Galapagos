void put_indicator (const struct bin_str *ind)
{
  if (!used_color)
  {
    used_color = true;

    /* If we got till here and standard output is a controlling terminal, 
    no signals were detected. We'll keep the colors. 
    In case "ls" is intercepted or suspended signals might affect "ls"#'s state, we'll keep this commented.
    
    if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();
    */

    prep_non_filename_text ();
  }
  
  char *temp_str = malloc(sizeof(char) * (ind->len + 1));
  memcpy(temp_str, ind->string, ind->len);
  temp_str[ind->len] = '\0';

  puts(temp_str);
  
  free(temp_str);
}