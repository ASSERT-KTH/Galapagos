Here is a variant of the function. 


#include <string.h>

void write_error(void) 
{
  int saved_errno = errno;
  if(fflush(stdout)==EOF) /* Checking if it results in an error */
   {
       fprintf(stderr,"Error flushing stdout buffer: %s",strerror(errno));
   }    
  clearerr(stdout);
  if(ferror(stdout)) /* Checking if it results in an error */
  {
       fprintf(stderr,"Error clearing stdout: %s",strerror(errno));  
  }
   
  if(saved_errno)
  {
		  fprintf(stderr, "Write error - %s \n", strerror(saved_errno));
		  exit(EXIT_FAILURE);
  }
}

This variant included <string.h> library to use strerror() to convert error number into readable messages and still assumes the output is in English. It adds more granular error checking to ensure potential error-inducing operations like fflush(stdout) and clearerr(stdout) were successful, providing valuable debug information if not, and prints an error message using the strerror() before exiting the program.
It maintains the original functionality - capturing the errno, flushing stdout, clearing any errors from stdout, reporting the write error, and subsequently terminating, except now provides more specific error messages.