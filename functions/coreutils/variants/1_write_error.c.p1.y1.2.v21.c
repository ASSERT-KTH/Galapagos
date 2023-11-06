1. Variant using nested function calls

void write_error(void)
{
    error
    (
        EXIT_FAILURE, 
        errno,
        _("write error")
    );
    fflush(stdout);
    clearerr(stdout);
}


2. Variant reusing the error variable

void write_error(void)
{
    int retVal = errno;
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, retVal, _("write error"));
} 


3. Error message as a defined variable:

void write_error(void)
{
    int saved_errno = errno;
    const char *errorMessage = _("write error");
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, saved_errno, errorMessage);
} 


4. Single line variant with ternary operator:

void write_error(void)
{
    int saved_errno = errno;
    fflush(stdout) ? clearerr(stdout) : error(EXIT_FAILURE, saved_errno,  _("write error"));
} 


5. Use of separate variable for error message:

void write_error(void)
{
    int saved_errno = errno;
    char* er_msg = _("write error");
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, saved_errno, er_msg);
} 
