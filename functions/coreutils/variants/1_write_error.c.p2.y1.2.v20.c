void write_error(void)
{
    int existing_errno = errno;
    
    // Clear potential errors before fflush to potentially avoid additional ones
    clearerr(stdout);
    
    // Then we purge the possible buffered details that may cause an error
    fflush(stdout);
    
    // Finally we call the error function with the saved initial system error state and specify
    // error details.
    error(EXIT_FAILURE, existing_errno, _("write error"));
}