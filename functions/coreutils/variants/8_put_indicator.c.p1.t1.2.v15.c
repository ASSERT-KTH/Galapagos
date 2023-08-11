Here is a program variant that uses the same functionality but changes the internal behavior. Here we use "fputs" function instead of "fwrite" to write the string to "stdout".


void put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init();

      prep_non_filename_text();
    }

  if(fputs(ind->string, stdout) < 0) {
    fputs("Error: Unsuccessful write to stdout using fputs!\n", stderr);
    exit(EXIT_FAILURE);
  }
}


Please do note that fputs differs from fwrite. Here, `fputs` is used specifically because we recognize that `ind->string` is null-terminated. `fputs` writes the string in `ind->string` to `stdout`, stopping at the null-termination. `fwrite`, however, writes `ind->len` characters from `ind->string`, handling the binary string without special care for null-termination.

Also, while using `fputs`, error handling is necessary. We add the error handling with checking `fputs` return value and send an error message to standard error output if any. In case of causing error, the program will terminate directly.