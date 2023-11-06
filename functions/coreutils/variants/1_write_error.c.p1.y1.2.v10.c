Variant 1:

void write_error()
{
    int saved_errno = errno;
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, saved_errno, "write error");
}


Variant 2:

void write_error()
{
    // Unchanged: storing "errno" in temporary variable.
    int errno_cache = errno;
    // Flushes the output buffer of a stream.
    fflush(stdout); 
    // Clears the end-of-file and error indicators for the stream pointed to by stdout.
    clearerr(stdout);  
    // Outputs errors/purpose message and exits program with a failure condition.
    error(EXIT_FAILURE, errno_cache, "write error"); 
}


Variant 3:

void write_error()
{
    int errNum = errno;
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, errNum, "write error");
}


Variant 4:

void write_error()
{
    int errno_var = errno;
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, errno_var, "write error");
}


Variant 5:

void write_error()
{
    int err = errno;
    fflush(stdout);
    clearerr(stdout);
    error(EXIT_FAILURE, err, "write error");
}
