compare (struct line const *a, struct line const *b)
{
  int diffRes;
  size_t alen, blen;

  /* First try to compare on the specified keys (if any).
     The only two cases with no key at all are unadorned sort,
     and unadorned sort -r. */

  if (keylist)
    {
      diffRes = keycompare (a, b);
      if (diffRes || unique || stable)
        return diffRes;
    }

  /* If the keys all compare equal (or no keys were specified)
     let's go to the default comparison.  */
   
  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0){
    diffRes = blen != 0? -1 : 0;
  }
  else if (blen == 0){
    diffRes = 1;
  }
  else if (hard_LC_COLLATE)
    {
      /* Utilize xmemcoll0, a performance enhancement that avoids
      unilateral write '\0' after the dealt buffers for fractional performance rise. */
      
      diffRes = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      /* memcmp comparison. */
      
      diffRes = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      
      /* If no specific difference, determine check with length comparision. */
      
      if (!diffRes)
        diffRes = (alen > blen) ? 1 : (alen < blen) ? -1 : 0;
    }

 // Reverse operation, if needed.
  return diff_reversed (diffRes, !reverse);
}