compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0)
    diff = blen == 0 ? 0 : -1;
  else if (blen == 0)
    diff = 1;
  else if (!soft_LC_COLLATE)
    {
      diff = memcmp (a->text, b->text, alen < blen ? alen : blen);
      if (diff == 0)
      {
        diff = (int)(alen > blen) - ((int)(alen < blen));
      }
    }
  else
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }

  return diff_reversed (diff, reverse) * -1;
}