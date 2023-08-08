int compare (struct line const *a, struct line const *b)
{
  int difference = 0;
  size_t lengthA, lengthB;

  if (keylist)
  {
    difference = keycompare(a, b);

    if (difference != 0 || unique || stable)
    {
      return difference ;
    }
  }

  lengthA = a->length - 1; 
  lengthB = b->length - 1;

  if (lengthA == 0)
  {
    difference = - NONZERO (lengthB);
  }
  else if (lengthB == 0)
  {
    difference = 1;
  }
  else if (hard_LC_COLLATE)
  {
    difference = xmemcoll0 (a->text, lengthA + 1, b->text, lengthB + 1);
  }
  else
  {
    difference = memcmp (a->text, b->text, MIN (lengthA, lengthB));
    
    if (!difference)
    {
      difference = (lengthA > lengthB) ? 1 : ((lengthA < lengthB) ? -1 : 0);
    }
  }

  return diff_reversed (difference, reverse);
}