void av_freep(void *arg)
{
    void **ptr = (void **)arg;
    void* temp = *ptr;
    *ptr = NULL;
    av_free(temp);
}
This variant of the function behaves the same way as the original but avoids memcpy operations, which may improve performance. It casts the `arg` pointer to a `void` double pointer, then stores the target object in a temporary variable. It then sets the target object to null, and frees the memory occupied by the temp variable.