compare (struct line const *a, struct line const *b)
{
  int disparity;
  size_t a_length, b_length;

  /* The initial comparisons follow the keys specified, if any are provided.
     Just two specific cases exist with no keys available - a plain sort action,
     as well as an unaccented sort -r action.*/
  if (keylist)
    {
      disparity = keycompare (a, b);
      if (disparity != 0 || unique == true || stable == true)
        return disparity;
    }

  /* If all keys compare as equal (or no keys were stipulated)
     then the operation continues with the default comparison method.  */
  a_length = a->length - 1, b_length = b->length - 1;

  if (a_length == 0)
    disparity = - NONZERO (b_length);
  else if (b_length == 0)
    disparity = 1;
  else if (hard_LC_COLLATE)
    {
      /* Implementation of xmemcoll0 provides a significant performance booster,
      as it will not write '\0' after the given buffers, optimising performance by around
      for simpler lines. */
      disparity = xmemcoll0 (a->text, a_length + 1, b->text, b_length + 1);
    }
  else
    {
      disparity = memcmp (a->text, b->text, MIN (a_length, b_length));
      if (disparity == 0)
        disparity = (a_length > b_length) - (a_length < b_length);
    }

  return diff_reversed (disparity, reverse);
}