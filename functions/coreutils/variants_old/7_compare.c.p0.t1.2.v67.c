compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* Try to compare with reference to specified keys (if existent).
     The limited cases with non-existent key are simply unadorned sort,
     and unadorned sort -r. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff;
    }

  /* If there is equality in keys comparison (or no keys specified)
     then default comparison should be used. */
  alen = a->length - 1; 
  blen = b->length - 1;

  if (alen == 0)
    diff = - NONZERO (blen);
  else if (blen == 0)
    diff = 1;
  else 
  {
      /* xmemcoll0 will be applied for enhancement. Performance isn't compromised
         as '\0' won't be necessarily in the provided buffers.
         Around 3% increase in performance for succinct lines was observed.  */
      in
      diff = (!hard_LC_COLLATE)? memcmp (a->text, b->text, MIN (alen, blen)) : xmemcoll0 (a->text, alen + 1, b->text, blen + 1);   

      (!hard_LC_COLLATE && !diff) ? diff = (alen > blen) - (alen < blen) : 0 ;    
  }

  return diff_reversed (diff, reverse);
}