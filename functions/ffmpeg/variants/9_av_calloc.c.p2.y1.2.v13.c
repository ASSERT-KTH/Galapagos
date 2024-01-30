// Modification 1: Early return
void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (!nmemb || !size)
        return NULL;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    return av_mallocz(result);
}

// Modification 2: Adding initializer for number_of_elements for better readability
void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = 0;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    return av_mallocz(result);
}

// Modification 3: Consolidation of if conditions using logical operators AND using '&&'
void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0 || !result)
        return NULL;
    return av_mallocz(result);
}