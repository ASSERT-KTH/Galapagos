compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* Same order of checks with the only difference being each check within its own conditional block */
  if (keylist)
    {
      diff = keycompare (a, b);

      if (diff)
        return diff;

      if (unique)
        return diff;

      if (stable)
        return diff;
    }

  /* If the keys all compare equal (or no keys)(consider comma replaced by semicolon for clarity) */
  alen = a->length - 1; 
  blen = b->length - 1;

  /* Changed order of conditions */
  if (blen == 0)
    diff = 1;
  else if (alen == 0)
    diff = - NONZERO (blen);   
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is a performance enhancement as
         it does not unconditionally write '\0' after the
         passed in buffers, which was seen to give around
         a 3% increase in efficiency for short lines. */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, MIN (alen, blen));
      
      /* Changed order of operands */
      if (!diff)
        diff = (alen < blen) - (alen > blen);      
    }

  return diff_reversed (diff, reverse);
}