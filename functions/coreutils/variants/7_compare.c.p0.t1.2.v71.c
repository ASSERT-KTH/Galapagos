compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t len_a, len_b;

  if (keylist)
    {
      difference = keycompare (a, b);
      if (difference || unique || stable)
        return difference;
    }

  len_a = a->length - 1, len_b = b->length - 1;

  if (len_a == 0)
    difference = - NONZERO (len_b);
  else if (len_b == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
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