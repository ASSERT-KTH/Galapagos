compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  if (keylist)
    {
      diff = keycompare (a, b);
      /* Here the only difference is changing the order of the conditional parts. 
         It initialize diff first to be sure that we can compare it later,
         regardless of whether only unique is true or only stable is true.
      */
      if (unique || stable || diff)
        return diff;
    }
 
  alen = a->length - 1, blen = b->length - 1;

  /* Here I took first the condition which comes to less complexity code first for performance enhancement. */
  if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else if (alen == 0)
    diff = - NONZERO (blen);
  else if (blen == 0)
    diff = 1;
  else 
    {
      diff = memcmp (a->text, b->text, MIN (alen, blen));
      if (!diff)
        diff = (alen > blen) - (alen < blen);
    }

  return diff_reversed (diff, reverse);
}