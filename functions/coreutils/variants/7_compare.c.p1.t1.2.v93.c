compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen = a->length - 1;
  size_t blen = b->length - 1;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (unique || stable)
        {
          return diff;
        }    
    }

  if (diff == 0)
    {
      if (alen == 0)
        diff = - NONZERO (blen);
      else if (blen == 0)
        diff = 1;
      else
        {
          if (hard_LC_COLLATE)
            {
              diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
            }
          else
            {
              diff = memcmp (a->text, b->text, MIN (alen, blen));
              if (diff==0)
                {
                  diff = (alen > blen) - (alen < blen);
                }
            }
        }
    }

  return diff_reversed (diff, reverse);
}