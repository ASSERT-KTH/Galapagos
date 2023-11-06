void wrapf (char const *message,...)
{
    va_list args;
    char *buf;
    int buflen, remain_space;

    va_start (args, message);
    buflen = vasprintf (&buf, message, args);
    va_end (args);

    if (buflen < 0)
        exit(1); // handles memory allocation failure

    remain_space = max_col - current_col;

    if (current_col > 0)
    {
        if (remain_space <= buflen)
        {
            fputc ('\n', stdout);
            current_col = 0;
        }
        else
        {
           fputc (' ', stdout);
           current_col++;
        }
    }

    fprintf(stdout, "%s", buf);
    current_col += buflen;
    free (buf);
}