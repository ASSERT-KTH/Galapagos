compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alength, blength;

  /* Initial comparison is done considering specified keys if there is any.
     In unadorned sort and unadorned sort -r there is no key at all. */
  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* If the keys are equal or no keys had been specified
     the code will proceed towards the default comparison.  */
  alength = a->length - 1, blength = b->length - 1;

  if (alength == 0)
    diff = - NONZERO (blength);
  else if (blength == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is used because it offers performance benefits.
         It doesn't always write '\0' after passed buffers resulting into a performance boost for short lines.  */
      diff = xmemcoll0 (a->text, alength + 1, b->text, blength + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, MIN (alength, blength));
      if (diff == 0)
        diff = (alength > blength) - (alength < blength);
    }

  // Reverse comparison if necessary.
  return diff_reversed (diff, reverse);
}