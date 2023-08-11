Sure, we can rearrange the behavior of function to achieve the same output.

void av_freep(void *arg)
{
    void *val;

    val = *(void **)arg; //We are directly assigning the pointer rather than memory copying
    *(void **)arg = NULL; //Assign a NULL rather than memory copying NULL value
    av_free(val);
}
