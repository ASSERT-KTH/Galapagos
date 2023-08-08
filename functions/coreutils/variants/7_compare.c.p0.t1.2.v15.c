compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* Try to compare on the specified keys first (if there are any specified) and return the result
    if there is a difference found or unique or stable sort is chosen. In unadorned sort, and unadorned sort -r,
    there won't be any keys specified. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* Default comparison is followed if there are no keys specified or if all the keys ended up being equal */
  alen = a->length - 1, blen = b->length - 1;

  if (alen == 0)
    diff = - (blen != 0);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* use xmemcoll0 because it doesn't automatically add '\0' at the end of the passed in buffers.
         This results in an aproximative 3% increase in performance for short lines. */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (diff == 0)
        diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
    }

  return diff_reversed (diff, reverse);
}