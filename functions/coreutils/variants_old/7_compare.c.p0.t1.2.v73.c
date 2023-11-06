compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t len_a, len_b;

  /* Attempt to compare based on specific keys(if they exist)
     The only two scenerios missing a key include unsophisticated sort,
     and unsophisticated sort with reverse. */
  if (keylist)
    {
      difference = keycompare (a, b);
      if (difference || unique || stable)
        return difference;
    }

  /* If no difference in keys(or no keys given), move to default comparison.*/
  len_a = a->length - 1, len_b = b->length - 1;

  if (len_a == 0)
    difference = - NONZERO (len_b);
  else if (len_b == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
      /* Making use of xmemcoll0 leads to improved performance,
         since it doesn't insert '\0' in buffers unconditionally,
         causing a slight performance boost for shorter lines.  */
      difference = xmemcoll0 (a->text, len_a + 1, b->text, len_b + 1);
    }
  else
    {
      difference = memcmp (a->text, b->text, MIN (len_a, len_b));
      if (!difference)
        difference = (len_a > len_b) - (len_a < len_b);
    }

  return diff_reversed (difference, reverse);
}