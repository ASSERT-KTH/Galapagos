freea (void *p)
{
  /* Check argument.  */
  if ((uintptr_t) p & (sa_alignment_max - 1))
    {
      /* p was not the result of a malloca() call.  Invalid argument.  */
      abort ();
    }
  /* Determine whether p was a non-NULL pointer returned by mmalloca().  */
  if ((uintptr_t) p & sa_alignment_max)
    {
      void *mem = (char *) p - ((small_t *) p)[-1];
      free (mem);
    }
}