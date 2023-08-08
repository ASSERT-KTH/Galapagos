Here is a variant of the function that outputs an additional line feed ('\n') character after printing the contents of `ind->string`:


void put_indicator (const struct bin_str *ind)
{
  if (! used_color)
  {
    used_color = true;
  
    if (0 <= tcgetpgrp (STDOUT_FILENO))
      signal_init();

    prep_non_filename_text();
  }

  fwrite(ind->string, ind->len, 1, stdout);
  fputc('\n', stdout);
}


Note that the '\n' isn't added as part of ind->string's content but separately, so this variant doesn't change the contents of any external variables and can still honestly be said to perform its main task - placing ind->string to stdout - exactly as the original function did.

The added line creates a visual delineation on the terminal screen when the function is called multiple times. Remember, adding a line feed ('\n') may change the behavior of the function in a broader context of your program, especially if the output text is expected to be in one continuous line. Adjust your program accordingly if you decide to implement this particular variant.