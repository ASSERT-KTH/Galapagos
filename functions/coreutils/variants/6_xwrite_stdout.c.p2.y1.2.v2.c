/*
First Variant:
In this version, firstly we check whether fwrite function has failed or not.
If fwrite function fails (returns a value less than nbytes), then an error is executed. This is different from original version where regardless of the return value by fwrite 
function, "error writing %s" runs due to condition in exit_failure function. 
In this variant error string has been explicitely defined inside of function.
*/

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  size_t bytes;
  if (n_bytes > 0) 
  {
    bytes = fwrite (buffer, 1, n_bytes, stdout);
    if(bytes < n_bytes) 
    {
      clearerr (stdout); /* To avoid redundant close_stdout diagnostic.  */
      char* error_string = "error writing %s";
      error (EXIT_FAILURE, errno, _(error_string),
             quoteaf ("standard output"));
    }
  }
}

/*
Second Variant:
 Here we use assert() function from "assert.h" library for error detection,
to check the return by fwrite. If it is not able to write all n_bytes onto STDOUT, then throws error.
on failing assert condition its stops the program and displays an error. 
*/
#include <assert.h>

void xwrite_stdout (char const *buffer, size_t n_bytes)
{
  if (n_bytes > 0) 
  {
    assert(fwrite (buffer, 1, n_bytes, stdout) == n_bytes);  
    /*above assert condition will fail and display error message if fwrite returns a value less than n_bytes due to not being able to write all n_bytes onto standard output.*/
  }
  /*execution of program will not reach here on assert() function failing leading the program to exit*/
}