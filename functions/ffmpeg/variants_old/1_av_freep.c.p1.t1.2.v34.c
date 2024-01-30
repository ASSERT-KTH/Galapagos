void av_freep(void *arg)
{
    void **ptr_to_free = (void **)arg; /*cast arg to pointer to pointer*/
    void *val = *ptr_to_free; /*dereference to get the actual pointer to be freed*/

    *ptr_to_free = NULL; /*make the pointer point to NULL*/
    av_free(val);
}