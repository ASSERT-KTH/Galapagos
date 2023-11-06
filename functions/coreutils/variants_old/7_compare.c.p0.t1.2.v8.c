compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff;
    }
  
  alen = a->length - 1;
  blen = b->length - 1;

  if (alen_init == false)
  {
    if (blen == 0)
      diff = -1;
    else
      diff = 1;
  }

  else if (blen_init == false && alen != 0)
    diff = 1;
  else if (hard_LC_COLLATE)
  {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
  }
  else
  {
      int min_len = (alen < blen) ? alen : blen;
      diff = memcmp (a->text, b->text, min_len);
      if (0 == diff)
         diff = (alen > blen ? 1 : -1);
  }

  return diff_reversed (diff, reverse);
}