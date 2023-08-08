compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen = 0, blen = 0;

  //Attempt to compare keys if provided
  if (keylist)
  {
    diff = keycompare (a, b);
    if (diff != 0 || unique || stable)
      return diff;
  }

  //Compute the lengths as this point non key matching cases reach
  alen = a->length - 1;
  blen = b->length - 1;


  if (alen == 0)
  {
    diff = - (blen != 0);
  }
  else if (blen == 0)
  {
    diff = 1;
  }
  else if (hard_LC_COLLATE)
  {
    // Optimize sorting by terminating initial collation condition for short lines
    diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
  }
  else
  {
    // Compute memory compare on the shortest text
    diff = memcmp (a->text, b->text, alen < blen ? alen : blen);

    // In event if there is no resulting difference
    if (diff == 0)
    {
      diff = alen > blen ? 1 : alen < blen ? -1 : 0;
    }
        
  }

  // if reversed return multiplied by -1, else return as is
  return reverse ? -diff : diff;
}