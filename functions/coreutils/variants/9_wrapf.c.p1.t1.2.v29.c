Here is a variant of the original function that changes its behavior but maintains its functionality. It keeps a control about whether a newline ('\n') was inserted, in order to apply/follow it up with the correct increment for `current_col`, depending on the newline, instead of basing it solely on `buflen`.


void wrapf(char const *message, ...)
{
    va_list args;
    char *buf;
    int buflen;
    bool added_newline = false;

    va_start(args, message);
    buflen = vasprintf (&buf, message, args);
    va_end(args);

    if (buflen < 0)
        xalloc_die();

    if (0 < current_col)
    {
        if (max_col - current_col <= buflen)
        {
            putchar('\n');
            current_col = 0;
            added_newline = true;
        }
        else
        {
            putchar(' ');
            current_col++;
        }
    }

    fputs(buf, stdout);
    free(buf);

    if (!added_newline)
        current_col += buflen;
}


In the original function, the `current_col` is incremented by the size of the buffer, no matter if the buffer contents were written to a new line or just appended at the end of the current line. This variant adjusts the increment of `current_col` accordingly to whether the new line was added before or later.