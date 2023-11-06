wrapf (char const *message,...)
{
    va_list args;
    char *buf;
    int buflen;

    va_start (args, message);
    buflen = vsnprintf (NULL, 0, message, args); // use vsnprintf to check needed buffer size, safe and error avoidance
    va_end (args);

    if (buflen < 0)
        xalloc_die ();

    buf = (char *)malloc(buflen + 1); // Allocate memory for buffer

    va_start (args, message); // Restart the argument list
    vsnprintf (buf, buflen + 1, message, args); // Now vsnprintf into the correctly sized buffer

    if (current_col > 0)
    {
        if (max_col - current_col <= buflen)
        {
            putchar ('\n');
            current_col = 0;
        }
        else
        {
            putchar (' ');
            current_col = current_col + 1;
        }
    }

    fprintf(stdout, "%s", buf); // Use fprintf to output the buffer
    free (buf);

    current_col = current_col + buflen;
}
