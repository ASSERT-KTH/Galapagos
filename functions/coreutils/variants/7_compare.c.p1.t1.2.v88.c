compare (struct line const *a, struct line const *b)
{
  /* Declare variables for difference and lengths of both lines.*/
  int difference;
  size_t length_a, length_b;

  /* Check for existence of key list and compare the lines by key. */
  if (keylist)
    {
      difference = keycompare(a, b);
      
      if (difference || unique || stable)
      {
        return difference;
      }
    }
  
  /* Calculate the length of both lines. */
  length_a = a->length - 1;
  length_b = b->length - 1;

  /* If a line has no length, set difference according to line b's length. */
  if (length_a == 0)
    difference = - NONZERO(length_b);
  
  /* If b line has no length, set difference to 1.*/
  else if (length_b == 0)
    difference = 1;
  
  /* If condition for LC_Collate comparison. */
  else if (hard_LC_COLLATE)
  {
    difference = xmemcoll0(a->text, length_a + 1, b->text, length_b + 1);
  }
  
  /* Fallback to default comparison.*/
  else
  {
    /* Directly compare a and b using memcmp till they differ.*/
    difference = memcmp(a->text, b->text, MIN(length_a, length_b));
   
    /* Check if the lengths are equal, if they are decide based on which is greater. */
    if (!difference)
      difference = (length_a > length_b) - (length_a < length_b);
  }

  /* Return the reversed difference. */
  return diff_reversed(difference, reverse);
}