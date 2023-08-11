Here's a variant C program that has similar behavior with original one, but clears the console window (used on windows) or terminal (used on Linux or MacOS) if there is an error in the formatting of the message:

char wrapf(const char *message, ...) {   
    va_list args;
    char *buf;
    int buflen;

    va_start(args, message);
    buflen = vasprintf(&buf, message, args);
    va_end(args);
    
    if (buflen<0) {
#ifdef _WIN32
        system("cls");
#else
        // Assume POSIX
        system("clear");
#endif
        xalloc_die ();
    }
    
   if(0 < current_col) {
        if(max_col - current_col <= buflen) {
            putchar('\n');
            current_col=0;
        }
        else {
            putchar(' ');
            current_col++;
        }
    }
    
    fputs(buf, stdout);
    
    free(buf);
    current_col += buflen;
}         
Note that above code uses 'system' call, which lowers the security and allows injection of any command. But this is just an example and might not fit for all environments. So always bear this in your mind before directly use this in production.