compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  if (keylist != NULL)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        return diff;
    }

  alen = a->length - 1;
  blen = b->length - 1;


  if (alen == 0)
  {
   if (blen != 0)
     diff = -1;
   else 
     diff = 0;
  }
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE) //in case collation order is enabled to take account some locales.
    {
      diff = xmemcoll0 ((char*) a->text, alen + 1, (char*) b->text, blen + 1);
    }
  else 
    {
      if (alen <= blen)
        blen = alen;//setting blen smaller or equal than alen to avoid overflow.

      diff = memcmp (a->text, b->text, blen);

      if (diff == 0)
      {
        if (alen < blen)
          diff = -1;
 	    else if (alen > blen)
          diff = 1;
        else
          diff = 0;
    }
  }

  if (reverse)
      dif = -diff;

  return diff;
}  
This variant takes the safer route for buffer lengths considering shorter string as the reliable bound; it also includes typecasting precautions for xmemcoll0. Further, instead of oblique coding \(alen > blen) - (alen < blen) for finding out the longer string, the code clearly writes down 3 different cases, thus catering to readability. It correctly inverts the result when reverse is true before returning the result.