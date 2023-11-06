Here is a variation of the original function that accomplishes the same goal with a similar footprint but with logical operators and pointers arithmetic which may change its behavior at a lower level with its tradeoffs in terms of memory use and time computation.


void av_freep(void *arg)
{
    void **pp = arg;
    void *p = *pp;
    
    *pp = NULL;
    av_free(p);
} 


The variant basically accesses the argument as a pointer to pointer, storing the original pointer in `p`. After that, the ref at the pointer is set to NULL, and the functional call to `av_free(p)` hypothetically releases the memory corresponding to the now unreachable data held by `p`.