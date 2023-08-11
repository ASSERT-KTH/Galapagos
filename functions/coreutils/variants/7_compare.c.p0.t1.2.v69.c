compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t len_a, len_b;

  // Try to compare based on provided keys first
  if (keylist)
    {
      difference = keycompare (a, b);
      if (difference || unique || stable)
        return difference;
    }

  // Comparison based on length if no keys provided or keys are equal
  len_a = a->length - 1, len_b = b->length - 1;

  if (len_a == 0)
    difference = - NONZERO (len_b);
  else if (len_b == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
      // Use xmemcoll0 for performance enhancement 
      difference = xmemcoll0 (a->text, len_a + 1, b->text, len_b + 1);
    }
  else
    {
      // Use memcmp to compare up to the shortest of the two strings
      difference = memcmp (a->text, b->text, MIN (len_a, len_b));
      if (!difference)
        difference = (len_a > len_b) - (len_a < len_b);
    }

  return diff_reversed (difference, reverse);
}