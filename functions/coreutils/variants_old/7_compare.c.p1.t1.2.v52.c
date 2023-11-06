The function implements comparison of lines with the respect of keys, uniqueness, stability, encoding locale, and reversing. The behavior change could be related to the order of resorting to different comparison strategies - in particular, by moving key comparison to appear the last in function logic. Here's one way to achieve this:


compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* First try to compare the lengths, if equal move to other comparisons. Disregard the keys comparison at this point. */
  alen = a->length - 1, blen = b->length - 1;

  if (alen == 0)
    diff = - NONZERO (blen);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
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
	
  if (diff || !(keylist))
    return diff_reversed (diff, reverse);

  /* If the keys all compare equal (or no keys were specified)
     earlier comparisons already took place. Now check for keys. */
  if (keylist)
    {
      diff = keycompare (a, b);
    }
	
  return diff_reversed (diff, reverse);
}

Note that this variant might not provide the same performance characteristic as the reference implementation, but should function the same in terms of comparing lines as per given requirements. The changes essentially defer the key comparison to the final stage, previously handled as the top priority.