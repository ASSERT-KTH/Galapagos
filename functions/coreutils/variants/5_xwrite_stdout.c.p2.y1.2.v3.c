
xwrite_stdout (char const *buffer, size_t n_bytes)
{
    size_t result;

    if (n_bytes > 0)
    {
        result = fwrite (buffer, 1, n_bytes, stdout);

        if(result < n_bytes)
        {
            clearerr(stdout);
            perror("Error while writing to standard output. Interupted the operation.");
            exit(EXIT_FAILURE);
        }
    }
}
