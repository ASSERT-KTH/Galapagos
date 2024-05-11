ccparray_get (ccparray_t *cpa, size_t *r_count)
{
  const char **result;

  if (cpa->out_of_core)
    {
      if (cpa->array)
        {
          xfree (cpa->array);
          cpa->array = NULL;
        }
      gpg_err_set_errno (cpa->out_of_core);
      return NULL;
    }

  result= cpa->array;
  if (r_count)
    *r_count = cpa->count;
  cpa->array = NULL;
  cpa->out_of_core = ENOMEM; /* hack to make sure it won't get reused. */
  return result;
}