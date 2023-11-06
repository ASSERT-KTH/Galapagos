compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen = 0, blen = 0;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff;
    }

  alen = a->length ? a->length - 1 : alen;
  blen = b->length ? b->length - 1 : blen;

  if (!alen)
    diff = blen ? -1 : 0;
  else if (!blen)
    diff = alen ? 1 : 0;
  else if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      size_t min_len = (alen < blen) ? alen : blen;
      diff = memcmp (a->text, b->text, min_len);
      if (!diff)
        diff = (alen > blen)? 1 : (alen < blen)? -1 : 0;
    }
   
  return diff_reversed(diff, reverse);
}