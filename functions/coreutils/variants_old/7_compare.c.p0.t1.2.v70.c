compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t length_a, length_b;

  if (keylist)
    {
      difference = keycompare (a, b);
      if (difference || unique || stable)
        return difference;
    }

  length_a = a->length - 1, length_b = b->length - 1;

  if (length_a == 0)
    difference = - NONZERO (length_b);
  else if (length_b == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
      difference = xmemcoll0 (a->text, length_a + 1, b->text, length_b + 1);
    }
  else
    {
      difference = memcmp (a->text, b->text, MIN (length_a, length_b));
      if (!difference)
        difference = (length_a > length_b) - (length_a < length_b);
    }

  return diff_reversed (difference, reverse);
}