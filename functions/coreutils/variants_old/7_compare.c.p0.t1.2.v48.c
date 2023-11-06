compare (struct line const *a, struct line const *b)
{
  int diff=0;
  size_t alen, blen;
  /* First try to compare on the specified keys (if any).
     The only two cases with no key at all are unadorned sort,
     and unadorned sort -r. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff || unique || stable)
        return diff;
    }

    
  /* If the keys all compare equal (or no keys were specified)
     fall through to the default comparison.  */
  alen = a->length - 1, blen = b->length - 1;

  if (alen == 0)
    diff = -(blen != 0);
  else if (blen == 0)
    diff = alen != 0;
  else if (hard_LC_COLLATE)
    {
      
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, alen<blen?alen:blen);
      if (diff == 0)
        diff = alen > blen?1:(alen < blen?-1:0);
    }

  return diff_reversed (-diff, reverse);
}