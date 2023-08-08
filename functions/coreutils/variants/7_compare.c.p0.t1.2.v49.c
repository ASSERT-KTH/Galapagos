compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (diff != 0 || unique || stable)
        {
          return diff;
        }
    }

  alen = a->length - 1;
  blen = b->length - 1;

  if (alen == 0 && blen != 0)
    { 
       diff = -1;
    }
  else if (blen == 0 && alen != 0)
    {
       diff = 1;
    }
  else if (hard_LC_COLLATE)
    {
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else 
    {
      diff = memcmp (a->text, b->text, (alen < blen) ? alen : blen );
      if (!diff)
      {
         if(alen > blen)
             diff = 1;
         else if(alen < blen)
             diff = -1;
         else 
             diff = 0;
      }
    }

  return diff_reversed (diff, reverse);
}