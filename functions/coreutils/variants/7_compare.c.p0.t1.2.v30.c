compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  alen = a->length - 1; 
  blen = b->length - 1;

  if (alen == 0) {
    diff = blen == 0 ? 0 : -1;
  } else if (blen == 0) {
    diff = 1;
  } else {
      if (hard_LC_COLLATE)
      {
        diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
      }
      else
      {
        diff = memcmp (a->text, b->text, MIN (alen, blen));
        if (!diff)
          diff = alen == blen ? 0 : (alen > blen ? 1 : -1);
      }
  }

  return diff < 0 ? !reverse : diff > 0 ? -reverse : 0;
}