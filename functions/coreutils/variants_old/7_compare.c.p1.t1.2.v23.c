compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  /* on the basis of the specified keys comparison if keys list is not Null*/
  if (keylist)
    {
      diff = keycompare (a, b);
      
      /* stopping comparison and 
      immediately returning difference if keys comparison is giving some difference
      'Unique' and 'Stable' flags are also used to stop if they are set (even when diff = 0) */
      if (diff != 0 || unique == 1 || stable == 1)
        return diff;
    }

  /* falling back onto default comparison method if no keys are provided.
   Also calculating difference if both keys compare equal */
  alen = a->length - 1;
  blen = b->length - 1;

  /* checking if either of them is of Zero length & adjusting 'diff' accordingly */
  if (alen == 0)
    diff = blen ? -1 : 0;
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* default collation order comparison when 'hard_LC_COLLATE' flag is set, 
      and special terminate symbol check conditional added */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      /* adjusted with 'MIN' function to take truncated length and decided based 
      on only the length's comparison, if memory bits compared equal */
      diff = memcmp (a->text, b->text, MIN (alen, blen));
      if (diff == 0)
        diff = (alen > blen ? 1 : (alen < blen ? -1 : 0));
    }

  /* reversing difference and using 'reverse' flag */
  return reverse ? - diff : diff;
}