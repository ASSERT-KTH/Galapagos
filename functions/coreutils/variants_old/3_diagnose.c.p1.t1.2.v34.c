The rewrite of the function can wrap the logic in an if-statement that checks if it is necessary to do any processing. In case errnum is zero and fmt string is null, it is pointless to proceed, and the function can rapidly exit. Despite the rapid exit, for cases when it makes sense to carry on with processing, the same functionality will be maintained.

Here is the modified version of the function, maintain the signature, doesn't use auxiliary nor helper function, no other text output except function's code.


void diagnose(int errnum, const char *fmt, ...) 
{
   if (errnum != 0 && fmt != NULL)
   {
       if (0 < progress_len)
       {
           fputc('\n', stderr);
           progress_len = 0;
       }

       va_list ap;
       va_start(ap, fmt);
       verror(0, errnum, fmt, ap);
       va_end(ap);
   }
}
