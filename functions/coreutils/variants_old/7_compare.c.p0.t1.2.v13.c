compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* Attempt a comparison based on given keys, if provided.
     If no keys are given, regular sorting or reversed sorting occur. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* If all keys show no differences (or no keys were provided),
     proceed with the standard comparison.  */
  alen = a->length - 1; blen = b->length - 1;

  if (alen == 0)
    diff = - NONZERO (blen);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 significantly improves eficiency.
         No conditional writing of '\0' after passed buffers allows about a
         3% performance increase for short lines.  */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, alen < blen ? alen : blen);
      if (diff == 0)
        diff = (int)(alen - blen > 0) - (int)(alen - blen < 0);
    }

  return diff_reversed (diff, reverse);
}