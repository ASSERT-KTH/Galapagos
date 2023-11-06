compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  if (keylist !== NULL)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique != 0 || stable != 0)
        return diff;
    }

  alen = a->length - 1; 
  blen = b->length - 1;

  if (alen == 0)
    diff = -abs(blen!=0);
  else if (blen == 0)
    diff = alen != 0;
  else if (hard_LC_COLLATE != 0)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen)?alen:blen);
      if (!diff)
        diff = (alen > blen) ? 1 : (alen < blen) ? -1 : 0;
    }
  
  return diff_reversed(diff, reverse != 0);
}
