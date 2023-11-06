I have applied a program transformation where the function will attempt to reattempt writing to the standard output whenever it fails. The upper limit to number of retries is currently set as 5. This will 'vertically stretch' function's duration, if failures occur, while retaining output.


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  int attempts_left = 5;
  if (n_bytes > 0)
  {
      while(attempts_left > 0) 
      {
	       if (fwrite (buffer, 1, n_bytes, stdout) >= n_bytes)
           break;

          clearerr (stdout); /* Clears buffer error */
          attempts_left--; /* Decrement retry counter */
      }

      /* If out of attempts, raise fatal error */
      if (attempts_left <= 0)
 	  {
		       error (EXIT_FAILURE, errno, _("error writing %s"),
             quoteaf ("standard output"));
 	  }
   }
}
