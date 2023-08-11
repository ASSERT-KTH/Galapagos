Here is a modified version of the function that operates with the same functionality:


void av_freep(void *arg)
{
    void *val = *(void **)arg;
    *(void **)arg = NULL;
    if(val) 
    {
        av_free(val);
    }
}


This modified version performs the same operations as the original. However, it uses direct dereferencing and assignment to perform its actions, rather than using `memcpy()`. First, it grabs the pointer from the passed in double pointer `arg`, then it sets the original pointer stored in `arg` to null, and finally it frees the originally-stored pointer if it wasn't null.
At former conversion via memcpy are replaced by calculations which are likely more efficient.

Please note, calls to non-standard functions such as `av_free()` are outside of the C standard version and require library support (i.e., the actual functionality of freeing memory pointed by void *val depends on the respective implementation).