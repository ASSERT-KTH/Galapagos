compare (struct line const *a, struct line const *b)
{
  int difference;
  size_t len_a, len_b;

  /* Comparison based on the keys only considered
     defaulted (unadorned) and reversed sorting, if keylist is provided */
  if (keylist)
  {
    difference = keycompare (a, b);
	if (difference || unique || stable)
	  return difference;
  }

  len_a = a->length - 1, len_b = b->length - 1;

  /* Checking for lengths of objects */
  if (len_a == 0)
    difference = - NONZERO (len_b);
  else if (len_b == 0)
    difference = 1;
 
  else if (hard_LC_COLLATE) 
  // Check LC_COLLATE setting, affecting string comparison
  {
    /* Making use of 'xmemcoll0' performance enhancement 
     to prevent re-writing '\0' buffer each time,
     reducing computation times. */
	 difference = xmemcoll0 (a->text, len_a + 1, b->text, len_b + 1);
  }
  else 
   /* Making use of standard 'memcmp' comparative function
     Comparing until the smallest buffer.\ */
   {
    difference = memcmp (a->text, b->text, len_a < len_b ? len_a : len_b);
    if (!difference)
      difference = (len_a > len_b) - (len_a < len_b);
   }
      
   /* Considering the reversal sorting parameter 'reverse', 
      update relative ordering return the result accordingly. */
   return diff_reversed (difference, reverse);
}