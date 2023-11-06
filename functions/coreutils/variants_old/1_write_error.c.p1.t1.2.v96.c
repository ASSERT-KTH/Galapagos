Below mentioned code changes the original function's behavior by adding an option to reattempt exception handling upon write error, though still exits the program if incapable of resolving.


#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h> 

void write_error (void)
{
    int saved_errno = errno;
    int attempts = 3;

    while(attempts--)
    {
      fflush (stdout); 
      clearerr (stdout); 
      if(ferror(stdout) == 0 && saved_errno != ENOMEM && saved_errno != EACCES)
      {
         /* In case error is solvable with retries, clear and directly returns to avoid failure. */
         errno = 0;
         return; 
      }

      sleep(1); /* breaks a second in case filesystem needs settling time */
    }

    /* If passed reattempts; run failure code. */
    error (EXIT_FAILURE, saved_errno, _("write error"));
}
 

The retries implemented provide the program with more robust write error handling. This can be particularly useful for temporary outages which can be resolved by rerunning . fflush() and clearerr(). Nonetheless, for critical errors such as ENOMEM and EACCES, the repeated attempt trial will be skipped to avoid program hang, and the function will directly proceed to exit the program.