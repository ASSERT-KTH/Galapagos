
void av_freep(void *arg)
{
  void *val = *((void**)arg);
  *((void**)arg) = NULL;
  av_free(val);
}



void av_freep(void *arg)
{
  void *val;
  val = *(void **)arg;
  *(void**)arg = NULL;
  av_free(val);
}



void av_freep(void *arg)
{
    void **val_ptr = (void **)arg;
    void *val = *val_ptr;
    *val_ptr = NULL;
    av_free(val);
}
