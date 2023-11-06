compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff;
    }

  alen = a->length - (a->length > 0 ? 1 : 0); 
  blen = b->length - (b->length > 0 ? 1 : 0);

  if (alen == 0)
    diff = -1 * (blen > 0);      
  else if (blen == 0)
    diff = (alen > 0);
  else if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);  
      if (!diff)
        diff = (int) (((double) alen/blen > 1) - ((double) alen/blen < 1));
    }

  return diff < 0 ? -1*reverse : (diff > 0 ? reverse : 0);
}