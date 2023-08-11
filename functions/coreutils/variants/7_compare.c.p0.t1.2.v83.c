compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* Attempt to compare on the specified keys first, if any exist. 
     The cases having no key are sort without any decorations,
     and sort -r without any decorations. */
  if (keylist != NULL)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique != 0 || stable != 0)
        return diff;
    }

  /* Default comparison is implemented for case when
     All keys are comparable and equal or no keys specified */
  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0 && blen != 0)
    diff = - NONZERO (blen);
  else if (blen == 0 && alen != 0)
    diff = 1;
  else if (alen != 0 && blen != 0 && hard_LC_COLLATE)
    {
      /* As it give perf boost with not writing NULL always
         Use xmemcoll0 for mem comparison  */
      diff = xmemcoll0 (a->text, a->length, b->text, b->length);
    }
  else if (alen != 0 && blen != 0)
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if (diff == 0)
        diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0);
    }

  return diff_reversed (diff, reverse > 0 ? 1 : 0);
}