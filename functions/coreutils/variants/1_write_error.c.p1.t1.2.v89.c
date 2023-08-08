Sure, the desired functionality can be achieved through different combinations of the same functions in the same function. So the variant function could look something like this:


write_error (void)
{
    clearerr (stdout);
    int saved_errno = errno;
    fflush (stdout);
    error (EXIT_FAILURE, saved_errno, _("write error"));
}

Here, the order of calling `clearerr (stdout);` and `int saved_errno = errno;` calls has been switched, however the overall effect should be the same. The other commands stay basically the same, hence ensuring the function's original purpose.