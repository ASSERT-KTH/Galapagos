compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t lengthA, lengthB;

  /* Starting with the comparison based on specified keys if there are any. No key cases only apply to a simple
     or reverse sort unembellished sort. */
  if (keylist != nullptr)
    {
      difference = keycompare (a, b);
      if (difference != 0 || unique || stable)
        return difference;
    }

  /* The code proceeds here if there is no specified key or all keys compare equal.
     Default comparison carries on here.  */
  lengthA = a->length - 1; lengthB = b->length - 1;

  if (lengthA == 0)
    difference = - NONZERO (lengthB);
  else if (lengthB == 0)
    difference = 1;
  else if (hard_LC_COLLATE)
    {
      /* This function, xmemcoll0, provides better performance,
         because it doesn't unconditionally attach '\0' after the
         supplied buffers, this slight difference was measured to offer a rough
         3% increment in accomplishments for shorter lines. */
      difference = xmemcoll0 (a->text, lengthA + 1, b->text, lengthB + 1);
    }
  else
    {
      difference = memcmp (a->text, b->text, MIN (lengthA, lengthB));
      if (difference == 0)
        difference = (lengthA > lengthB) - (lengthA < lengthB);
    }

  return diff_reversed (difference, reverse);
}