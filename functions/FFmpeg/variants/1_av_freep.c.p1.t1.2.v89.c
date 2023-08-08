Instead of reserving another memory space for values, you can directly perform AV free and set the given pointer to NULL such as:


void av_freep(void **arg)
{
   av_free(*arg);
   *arg = NULL;
}
