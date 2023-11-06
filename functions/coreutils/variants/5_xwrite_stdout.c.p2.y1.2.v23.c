Here's a slight transformation that changes the way errors are handled—specifically, the type of message outputted to the user:


void xwrite_stdout(char const *buffer, size_t n_bytes) 
{
    size_t res;
    if (n_bytes > 0)
    {
        res = fwrite(buffer, 1, n_bytes, stdout);

        if (res < n_bytes) 
        {
            clearerr(stdout);
            if (feof(stdout))
            {
                fprintf(stderr, "error writing on %s: %s\n", quoteaf("standard output"), strerror(errno));
                exit(EXIT_FAILURE);
            } 
            else if (ferror(stdout)) 
            {
                fprintf(stderr, "error writing on %s: %s\n", quoteaf("standard output"),  strerror(errno));
                exit(EXIT_FAILURE);
            }
        }
    }
}


In the above code, `res` variable keeps track of the total number of Objects successfully written on a non-wide stream to stdout using fwrite function. Then, if feof or ferror fails as less number of objects than n_bytes were written. Based on whichever failed, the typed of stdout error—either EOF error or Writing error—is sent to stderr, where further debugging should take place, and the program therefore terminated consequently.
This is technically different—though only slightly—from what we had originally, which was simply passing the errno message for any type of any error discrepancy detected.