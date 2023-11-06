compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen, blen;

  if (keylist)
    {
      
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
      {
        return diff;
      }

    }
  
  alen = a->length - 1, blen = b->length - 1;

  switch (alen)
  {
     case 0:
        diff = - NONZERO (blen);
        break;
     default:
        if(blen == 0)
        {
         diff = 1;
        }
        else if (hard_LC_COLLATE)
        {
         diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
        }
        else
        {
          size_t shorter = (alen < blen) ? alen : blen;
          diff = memcmp (a->text, b->text, shorter);
          if (!diff) diff = (alen > blen) - (alen < blen);
        }
  }

  return diff_reversed (diff, reverse);
}