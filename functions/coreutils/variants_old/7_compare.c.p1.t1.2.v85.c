Sure, a program variant may consider checking right away if 'a' or 'b' are empty then proceeding with rest, comparing this to the previous version might make things faster when dealing with large scale data. Here's how it might look:


compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  alen = a->length - 1, blen = b->length - 1;

  if (alen == 0) {
    diff = - NONZERO (blen);
    return diff_reversed (diff, reverse);
  } 
  else if (blen == 0) {
    diff = 1;
    return diff_reversed (diff, reverse);
  }

  /* First try to compare on the specified keys (if any).
     The only two cases with no key at all are unadorned sort,
     and unadorned sort -r. */
  if (keylist)
  {
    diff = keycompare (a, b);
    if (diff || unique || stable)
      return diff;
  }
  
  /* If the keys all compare equal (or no keys were specified)
     move down to the default comparison.  */

  if (hard_LC_COLLATE)
  {
    /* xmemcoll0 is a performance enhancement as
       it will not unconditionally write '\0' after the
       passed in buffers, which was seen to give around
       a 3% increase in performance for short lines.  */
    diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
  }
  else
  {
    diff = memcmp (a->text, b->text, MIN (alen, blen));
    if (!diff)
      diff = (alen > blen) - (alen < blen);
  }

  return diff_reversed (diff, reverse);
}

By moving the check for empty values to the top of the function you can exit and return a result much quicker than in previous implementation.