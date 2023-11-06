Variant 1: Using `fprintf`


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0)
    {
        for(size_t i=0; i<n_bytes; i++)
	    {
            if(fputc(buffer[i], stdout) == EOF)
		    {
                clearerr(stdout);
                error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
		    }
        }
    }   
}

Variant 2: Using `puts`


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0)
    {
        char temp[n_bytes+1]; 

        strncpy(temp, buffer, n_bytes);
        temp[n_bytes] = '\0'; 

        if (puts(temp) < 0) 
        {
           clearerr(stdout);
           error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
        }
    }  
}


Variant 3: Using `putchar`


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0)
    {
        for(int i = 0; i<n_bytes; i++)
        {
            if (putchar(buffer[i]) == EOF) 
            {
                 clearerr(stdout);
                 error(EXIT_FAILURE, errno, _("error writing %s"), quoteaf("standard output"));
            }
        }
    }  
} 
