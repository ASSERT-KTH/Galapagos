compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* First alternative to unspecified comparison 
    on the specified keys, 2 cases : no key
    or unadorned sort -r. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff;
    }

  /* If keys are equal or no keys specified,
     use the default comparison.  */
  alen = a->length - 1, blen = b->length - 1;

  if (alen == 0)
    diff = blen ? -1 : 0; // Positive NONZERO simplified 
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* Performance enhancement: xmemcoll0 
         does not write '\0' after passed buffers.  */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (!diff)
        diff = (alen > blen) ? 1 : (alen < blen) ? -1 : 0;
    }

  return diff_reversed (-diff, -reverse);
}