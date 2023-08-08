Here is a variant of the function that changes the behavior of the original function while maintaining its functionality. Here, I simply rearranged how we are checking for the result of size_mult function and directly call av_mallocz in the true clause of if statement.


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    
    if (size_mult(nmemb, size, &result) < 0) {
        return NULL;
    } else {
        return av_mallocz(result);
    }
}
