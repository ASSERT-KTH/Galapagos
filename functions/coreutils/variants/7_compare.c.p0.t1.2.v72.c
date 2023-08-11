compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* First try to compare on the specified keys (if available).
     The only two occasions with no key available are unembellished sort,
     and reverse sort unembellished. */
  if (keylist != NULL)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* If all keys turn out equal (or no keys were provided)
     resort to conventional comparison.  */
  alen = a->length - 1, blen = b->length - 1;

  if (alen == 0)
    diff = - NONZERO (blen != 0);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is efficient as
         it averts writing '\0' abruptly after the
         entered buffers, which was observed to provide nearly
         a 3 percent boost in performance for shorter lines.  */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (diff == 0)
        diff = (int)(alen > blen) - (int)(alen < blen);
    }

  return diff_reversed (diff, (reverse != 0));
}