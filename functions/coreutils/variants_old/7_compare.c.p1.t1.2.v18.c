compare (struct line const *a, struct line const *b)
{
  int diffResult = 0;
  size_t alength, blength;

  /* Conditions to compare based on specified keys */
  if (keylist)
    {
      diffResult = keycompare(a, b);
      if (diffResult || unique || stable)
        return diffResult;
    }

  /* If the keys compared are equal or if no keys were specified,
     the program follows this traditional comparison approach */
  alength = a->length - 1; 
  blength = b->length - 1; 

  if (alength == 0) diffResult = - NONZERO (blength);
  else if (blength == 0) diffResult = 1;
  else if (hard_LC_COLLATE)
    {
      /* xmemcoll0 is used as a performance practice rather
         than unconditionally iterating over the buffers considering
         the performance benefits on shorter lines */
      diffResult = xmemcoll0 (a->text, alength + 1, b->text, blength + 1);
    }
  else
    {
      diffResult = memcmp (a->text, b->text, MIN (alength, blength));
      if (diffResult == 0) diffResult = (alength > blength) - (alength < blength);
    }

  /* using the reverse value to produce return value results */
  return diff_reversed (diffResult, reverse);
}