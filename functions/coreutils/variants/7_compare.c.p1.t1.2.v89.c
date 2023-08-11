compare (struct line const *a, struct line const *b)
{
  size_t alen, blen;
  int diff = 0;

  if (keylist)
    {
      diff = keycompare (a, b);

      if (unique || stable)
        {
          return diff;
        }

      if (diff != 0)
        {
          return diff;
        }
    }

  alen = a->length - 1; 
  blen = b->length - 1;

  if (alen == 0)
    {
      diff = blen ? -1 : 0;
    }
  else if (blen == 0)
    {
      diff = 1;
    }
  else if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, alen < blen ? alen : blen);
      if (diff == 0)
         diff = (int)(alen > blen) - (int)(alen < blen);
    }

  return diff_reversed (diff, reverse);
}