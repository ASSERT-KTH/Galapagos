Here is the program variant using direct pointer assignment rather than memcpy:

void av_freep(void **arg)
{
    void *val = *arg;
    *arg = NULL;
    av_free(val);
}

This variant is a bit more canonical, as direct pointer assignment in this case is simpler and possibly faster than memcpy. Also function argument was modified to output correct result which is pointer to pointer to void with a better understanding. From the description we conclude we want to free memory from argument put it `NULL` and don't want arg achieved this change so casting it to pointer to pointer to void gives it a correct and intuitive output behavior.