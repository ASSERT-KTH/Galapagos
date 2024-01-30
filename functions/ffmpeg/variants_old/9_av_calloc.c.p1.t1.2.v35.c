Here is a program variant that utilizes a slight variation, by directly returning the result of the function av_mallocz already within the condition. Please make sure that function av_mallocz can return NULL when allocation failed because this change assumes that behavior.


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        return av_mallocz(0);
    return av_mallocz(result);
}


This program variant keeps the control flow, but adds an additional call of av_mallocz. This new call simplifies the code and removes the need for conditional constructs. Basically, instead of returning NULL directly when size calculation fails, it's now calling av_mallocz with zero size. Under normal circumstances, a call to malloc with a zero size does return a distinct non-null pointer (which may not be de-referenced), thus ensuring that allocation "succeeds".
Most systems return a pointer that can be safely passed to free in such scenarios, which is generally beneficial for client code. But the relevant fact is that you need to make sure av_mallocz behaves safely when called with zero size.
In production code, direct return of NULL could be a fair choice as it avoids unnecessary function call and states the idea that nothing is allocated outright, while still behaving correctly on standards-compliant systems.