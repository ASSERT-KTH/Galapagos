Below are some variations of the original function that preserve its feature.

Variant 1:

void av_freep(void *arg) 
{
    void *val = NULL;
    val = *((void **)arg); 
    *((void **)arg) = NULL; 
    av_free(val);
}


Variant 2:

void av_freep(void *arg) 
{
    void *val = NULL;

    val = *( (void **)arg );
    *( (void **)arg ) = 0;

    av_free(val);
}


Variant 3: Using `NULL` directly.


void av_freep(void **arg) 
{
    void *val;

    val = *arg;
    *arg = NULL;

    av_free(val);
}


Although it changes the function signature, it maintains the "spirit" of the original function signature (using pointers).

Variant 4: Less changes, reinterpret casting to update `arg` after copying it to `val`


void av_freep(void *arg)
{
    void *val = NULL;

    memcpy(&val, arg, sizeof(val));
    *(void **)arg = NULL;

    av_free(val);
}
