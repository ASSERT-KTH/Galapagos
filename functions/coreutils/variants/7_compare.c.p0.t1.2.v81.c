compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* First consider comparing on the specified keys if it is not empty. */
  if (keylist)
    {
      diff = keycompare (a, b);
      /* Return the result if it is distinct or the sort needs to be unique or stable. */
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* If all keys end up being equal or no keys are defined, move to standard comparison */
  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0)
    diff = - NONZERO ((!blen) ? 0 : 1);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* If collations are considered, xmemcoll0 can increase the performance as 
         it won't need to rewrite '\0' after the passed buffers.  */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      /* Linear memory comparison depending on the minimum of the lengths */
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (diff == 0)
        diff = ((alen > blen) ? 1 : ((alen < blen) ? -1 : 0));
    }

  /* Reverse the comparison, if necessary. */
  return (reverse ? -diff : diff);
}