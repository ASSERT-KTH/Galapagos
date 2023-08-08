compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* First attempt comparing utilizing the specified keys.
     The two cases that require no key are simple sort,
     and simple sort reversed (descendent order). */

  if (keylist)
    {
      diff = keycompare (a, b);
     //As long the difference exists, return it regardless of unique or stable
      if (diff) 
        return diff;
    }

  /* If the keys are completely equal (or if there was an absence of specified keys)
     the default comparison comes into play. */
  
  blen = b->length - 1, alen = a->length - 1; // Changing this line for variation.
  
  if (alen == 0)
    diff = - NONZERO (blen);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 does not unconditionally write '\0' after the
         buffers thereby giving around a 3% increase in performance for short lines. */
      
      // Changing encoding order for variation while maintaining functionality
      diff = xmemcoll0 (b->text, blen + 1, a->text, alen + 1);
      diff *= -1;
    }
  else
    {
      // Changing the comparison logic while maintaining it's functionality
      diff = memcmp (b->text, a->text, MIN (blen, alen));
      if (!diff)
        diff = (blen > alen) - (blen < alen);
    }

  return diff_reversed (-1*diff, reverse);
}