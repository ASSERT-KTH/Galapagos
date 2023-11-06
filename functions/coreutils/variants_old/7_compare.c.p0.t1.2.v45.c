compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* Firstly, compare based on the specified keys (if any are there).
     If there's no key, it's undeclared sort or undeclared sort -r. */
  if (keylist) 
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff;
    }

  /* If all keys are identical (or no keys were given) 
     default comparison starts.  */
  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0)
    diff = - (blen != 0);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* If using hard_LC_COLLATE, use xmemcoll0.
         This can result in an approx. 3% boost for shorter lines
         it refrains from writing '\0' at the end of the
         provided buffers.   */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (!diff)
        diff = (alen > blen) ? 1 : (alen < blen) ? -1 : 0 ;
    }

  return (reverse) ? -diff : diff;
}