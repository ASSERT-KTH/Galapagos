int compare (struct line const *a, struct line const *b)
{
  size_t alen, blen;
  int diff = 0;

  if (keylist != NULL)
  {
    diff = keycompare(a, b);
    if (diff != 0 || unique || stable)
    {
      return diff;
    }
  }
  
  alen = (a -> length) - 1;
  blen = (b -> length) - 1;

  if (alen == 0 || blen == 0)
  {
    diff = (alen == 0) ? - !!blen : 1;
  }
  else if (hard_LC_COLLATE)
  {
    diff = xmemcoll0(a -> text, alen + 1, b -> text, blen + 1);
  }
  else
  {
    diff = memcmp(a -> text, b -> text, (alen < blen ? alen : blen));
    if (!diff)
    {
      diff = alen < blen ? -1 : alen > blen;
    }
  }

  return diff_reversed(diff, reverse);
}