1. Throwing exceptions instead of errors.


#include <cstdio>
#include <cstdlib>
#include <stdexcept>

void xwrite_stdout(char const* buffer, size_t n_bytes)
{
    if (n_bytes > 0 && fwrite(buffer, 1, n_bytes, stdout) < n_bytes)
    {
        clearerr(stdout);
        throw std::runtime_error("error writing standard output");
    }
}


2. Using 'if else' logic.


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0) {
        if (fwrite (buffer, 1, n_bytes, stdout) < n_bytes) {
            clearerr (stdout);
            error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
        }
    }
}


3. Error checking function


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    size_t writeNo = fwrite (buffer, 1, n_bytes, stdout);
    if (n_bytes > 0 && writeNo < n_bytes)
    {
        clearerr (stdout);
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}


4. Structuring the error messages separately


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, stdout) < n_bytes)
    {
        clearerr (stdout);
        const char* errMsg = _("error writing %s");
        const char* quotedOutput = quoteaf ("standard output");
        error (EXIT_FAILURE, errno, errMsg, quotedOutput);
    }
}


5. Changing stdout to fout


void xwrite_stdout (char const *buffer, size_t n_bytes)
{
    FILE *fout=stdout;
    if (n_bytes > 0 && fwrite (buffer, 1, n_bytes, fout) < n_bytes)
    {
        clearerr (fout); 
        error (EXIT_FAILURE, errno, _("error writing %s"), quoteaf ("standard output"));
    }
}
