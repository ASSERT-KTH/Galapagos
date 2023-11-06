compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t a_len, b_len;

  /* Initial comparison based on defined keys if exist. If no key is define, we do simple sort or reverse sort.*/
  if (keylist)
    {
      difference = keycompare (a, b);
      if (difference || unique || stable)
        return difference;
    }

  /* If the keys yield equal results (or no keys were given) proceed with default comparison.*/
  a_len = a->length - 1, b_len = b->length - 1;

  if (a_len == 0)
    difference = - NONZERO (b_len);
  else if (b_len == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 provides performance benefit by not performing
         unnecessary '\0' writing after the given buffers, providing 
         approximately 3% performance increase for the short lines.  */
      difference = xmemcoll0 (a->text, a_len + 1, b->text, b_len + 1);
    }
  else
    {
      difference = memcmp (a->text, b->text, MIN (a_len, b_len));
      if (!difference)
        difference = (a_len > b_len) - (a_len < b_len);
    }

  return diff_reversed (difference, reverse);
}