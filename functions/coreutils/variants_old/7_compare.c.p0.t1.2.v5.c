compare_alternative (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* The primary comparison is based on the specified keys, if present. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* As the second option, if the keys are equal or not provided,
     the default comparison is applied using the lengths of the lines. */
  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0 && blen != 0)
    diff = -1;
  else if (blen == 0 && alen != 0)
    diff = 1;
  else if (alen != 0 && blen != 0 && hard_LC_COLLATE)
  { 
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
  }
  else if (alen != 0 && blen != 0)
  {
      diff = memcmp (a->text, b->text, MIN (alen, blen));
      if (diff == 0)
      {
        diff = (int)(alen == blen) - 1; 
        diff *= (int)(blen != alen);
      }
  }

  return diff_reversed (diff * (reverse > 0? -1:1));
}