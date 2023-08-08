compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* Compare using given keys. Without a key, it defaults to regular sort or reverse sort. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff;
    }

  /* If keys are all equal or no keys are specified, then default comparison is used. */
  alen = a->length - 1;
  blen = b->length - 1; // Added line breaks for readability

  if (alen == 0)
    diff = - NONZERO (blen);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 does not necessarily append '\0' to buffers and was seen to improve performance by around 3% for short lines. */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen); // Used a ternary operator instead of MIN macro for alen and blen comparison
      if (!diff)
        diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0); // Converted assignment into ternary operation sequence for readability purpose
    }

  /* This function transitions based on whether the diff is reversed */
  return diff_reversed (diff, reverse);
}