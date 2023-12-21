Sure, here is a program varient that replaces the usage of memcpy function, this version is more efficient where it directly de-references and assigns null:


void av_freep(void **arg)
{
    void *val = *arg;
    *arg = NULL;
    av_free(val);
}


This one maintains the functionality of the original program. It still gets the value from arg, sets the value at arg to NULL, and then frees the original value.