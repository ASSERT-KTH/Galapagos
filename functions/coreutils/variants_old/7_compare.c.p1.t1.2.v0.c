int compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  /* Key comparison if keys are available.
     No key scenarios are for simple sorts and reverse sorts without modifiers. */
  if (keylist)
    {
      diff = keycompare (a, b);
      /* If keys are distinct, or operation needs unique or stable behavior, return key difference. */
      if (diff != 0 || unique || stable)
        return diff;
    }

  /* If keys are identical (or no keys were given),
     the comparison continues with line lengths. */
  alen = a->length - 1;
  blen = b->length - 1;

  /* Conditions for assessing values that could affect the difference attributed to lines comparisons. */
  if (alen == 0)
    diff = - (blen != 0); // utilizing NONZERO as (x != 0)
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* Maximizing performance while comparing collation order for non identical key lines */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      /* If neither of the conditions are met, uses the memcmp.
         Proceeds for another line length comparison if identical character arrays are found.  */
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen); // utilizing MIN as (x < y) ? x : y
      if (diff == 0)
        diff = (alen > blen) ? 1 : ((alen < blen) ? -1 : 0); // changing bracket notation (var > const) - (var < const) for branched ternary
    }

  /* Apply reversal to calculated difference when requested */
  return diff_reversed (diff, reverse);
}