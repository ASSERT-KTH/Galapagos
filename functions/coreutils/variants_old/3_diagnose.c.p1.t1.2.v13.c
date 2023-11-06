Here's a variant of the function, that maintains its current functionality but allows users to specify that no newline character ('\n') should be printed before the error message.


diagnose (int errnum, char const *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);

  if(progress_len && strcmp(fmt, "no_newline") != 0) 
  {
      fputc ('\n', stderr);
      progress_len = 0;
  } else if(progress_len){
      fputc (' ', stderr);
      progress_len = 0;
  }
 
  if(!strcmp(fmt, "no_newline")) 
  {
      char const *new_fmt = va_arg(ap, char const *);
      verror(0, errnum, new_fmt, ap);
  } else {
      verror(0, errnum, fmt, ap);
  }

  va_end(ap);
}

Now, 
if you want to print the message without preceding newline, 
you can simply use `diagnose` function like this:

diagnose(ERRNUM, "no_newline", "Your message");

Ordinary usage stays same: 

diagnose(ERRNUM, "Your message");
