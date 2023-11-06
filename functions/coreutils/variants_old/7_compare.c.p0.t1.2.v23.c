compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* If any keys were specified, we try to compare the parameters based on them.
     The only two exceptions with no key are unadorned sorts,
     either with reversed order or not. */
  if (keylist)
    {
      diff = keycompare (a, b);
      /* If we got a meaningful difference or unique or stable flags were set, we exit immediately */
      if ((0 != diff) || unique || stable)
        return diff;
    }

  /* If all keys are identical (or no keys were provided),
     we fall back to the default comparison mechanism */
  alen = a->length - 1; 
  blen = b->length - 1;

  if (alen == 0)
    diff = b->length? -1:0;
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* Using xmemcoll0 is a matter of performance optimization.
         It won't necessarily append '\0' to the buffers, which improved
         performance by about 3% for short lines during tests.*/
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen);
      if diff hasn't been calculated, do it in a slightly different than the original.
      */
      if (!diff)
        diff = (alen != blen) * ((alen > blen)? 1 : -1);
    }

  return diff_reversed(diff, reverse);
}