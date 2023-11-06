compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* Instead of returning immediately after keys comparison, we keep the diff for later checks */
  if (keylist)
    {
      diff = keycompare (a, b);
      if ((diff || unique || stable) != 0)
      {
          return diff;
      }
    }

  alen = a->length - 1, blen = b->length - 1;

  /* Slight modification in the handling of zero cases. Handles two cases in same if condition */
  if (alen == 0 || blen == 0)
  {
    diff = (alen == 0) ? - NONZERO(blen) : 1;
  }
  /* This condition was in the default fallback, taken it outside */
  else if (npasses && a <= tmp && b > buf)
  {
     return diff;
  }
  else if (hard_LC_COLLATE)
  {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
  }
  else
  {
      diff = memcmp (a->text, b->text, MIN (alen, blen));
      if (0 == diff)
        diff = (alen > blen) - (alen < blen);
  }

  /* Check diff in reverse was initially in the return statement. Changed to make it more readable */
  if(reverse != 0)
    diff = -diff;

  return diff;
}