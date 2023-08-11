Compare (struct line const *a, struct line const *b)
{
  int difference=0;
  size_t len_a, len_b;

  /* If there's a key list, apply key comparison first,
  which is relevant for sort and sort -r without any adornment. */
  if (keylist != NULL)
  {
    difference = keycompare(a, b);
    if (difference != 0 || unique || stable)
      return difference;
  }

  /* Move to the default comparison mode if the keys are equal or there aren't any specified. */
  len_a = a->length - 1;
  len_b = b->length - 1;

  /* Considering different cases based on the lengths of a 
  and b being 0 or non-zero. */
  if (len_a == 0)
    difference = -NONZERO(len_b);
  else if (len_b == 0)
    difference = 1;
  else if(hard_LC_COLLATE)
  {
 
    /* Not writing '\0' unconditionally to the buffers leads to 
    about 3% performance improvement for short lines. Hence utilising xmemcoll0 function here. */
    difference = xmemcoll0(a->text, len_a + 1, b->text, len_b + 1);
  } 
  else
  {
    /* We consider the minimum value between len_a and len_b for comparison
    If there is no difference then we check if len_a is greater than len_b, returns
    1 if true and returns -1 if false. */
    difference = memcmp(a->text, b->text, MIN(len_a, len_b));
    if (difference == 0)
      difference = (len_a > len_b) - (len_a < len_b);
  }

  /* After the above steps, return the reversed diff */
  return diff_reversed(difference, reverse);
}
