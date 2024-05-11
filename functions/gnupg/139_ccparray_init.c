ccparray_init (ccparray_t *cpa, unsigned int initialsize)
{
  if (!initialsize)
    cpa->size = 16;
  else if (initialsize < (1<<16))
    cpa->size = initialsize;
  else
    cpa->size = (1<<16);

  cpa->count = 0;
  cpa->out_of_core = 0;
  cpa->array = xtrycalloc (cpa->size, sizeof *cpa->array);
  if (!cpa->array)
    cpa->out_of_core = errno;
}