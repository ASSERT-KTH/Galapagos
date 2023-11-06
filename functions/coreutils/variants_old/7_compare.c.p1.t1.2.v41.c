compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  // try to compare across specified keys only if the keylist is there.
  // if unadorned sort or unadorned sort -r is specified, no key will be present.
  
  if (keylist)
  {
    diff = keycompare (a, b);
    if (diff || unique || stable)
    {
      return diff;
    }
  }

  //default comparison happens here if no keys are specified, or keys comparison equals

  alen = a->length - 1,
  blen = b->length - 1;
  diff = (alen == 0) ? - NONZERO (blen) : (blen==0) ? 1 : 0;
  
  if(diff!=0)
  {
    return diff_reversed (diff, reverse);
  }

  else 
  {
    if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    } else {
      diff = memcmp (a->text, b->text, MIN (alen, blen));
      if (!diff)
        diff = (alen > blen) - (alen < blen);
    }

    return diff_reversed (diff, reverse);
  }
}