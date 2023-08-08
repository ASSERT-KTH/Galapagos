Sure, let's write the variant. The original functionality of the function is that it saves the current value of errno, makes sure that stdout (Standard Output) is flushed and close then while showing the stored errno message.

Here's a variant that changes the behavior of the code, but it preserves the original functionality:


#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <gettext.h>

void write_error(void) 
{
  int my_errno = errno;
  fclose(stdout);
  stdout = fopen("NUL", "w");
  error(EXIT_FAILURE, my_errno, gettext ("write error"));
}

This variant is first closing the stdout stream manually with fclose, then reopens it directed to NULL or a place where files cannot be written to, so any further writes to it will generate an error.