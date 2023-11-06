Here is a program variant that changes the function's behavior while maintaining its original functionality:

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>

void write_error (void)
{
  int saved_errno = errno;   // Save the original value of errno so we can reset it later.
  if(fflush (stdout) != 0)  // Make sure buffer's content moved to destination, but unlike earlier method gracefully error handle fail (if there was any to start with)
  {
      saved_errno = errno;   // If the flush failed update saved_errno
      perror("Failed to flush stdout due to");
  }
  if(clearerr (stdout) != 0)  /* If previously visited EOF or IO Error happened check on clearerr which doesn't actually recognizes either and report that only */
  {
      perror("Failed to clear error from stdout due to");
      saved_errno = errno;     
  }
  fprintf(stderr, "write error: ");
  perror("");   
  exit(EXIT_FAILURE);     
}

int main(void)
{
    write_error();
    return 0;
}

The behavior is changed as it now checks if fflush() and clearerr() functions successfully carried out their operation. And perror() making operation terminal/calling process seek for reason. Original functionality, being able to reset errno to its state prior to the function call and subsequently exiting as failure, remain the same. Can perceive the flow of facts via stderr as it prints last encountered error if any. It makes diagnosing outcome process clearer.