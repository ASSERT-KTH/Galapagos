compare (struct line const *a, struct line const *b)
{
  int diff = 0;
  size_t alen = 0, blen = 0;

  alen = a->length - 1;
  blen = b->length - 1;

  if (keylist)
    {
      diff = keycompare (a, b);
      if (!diff && !(unique || stable))
        {
          if (alen == 0)
            diff = - !!blen;
          else if (blen == 0)
            diff = 1;
          else
            {
              if (hard_LC_COLLATE)
                diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
              else
                {
                  int len_diff;
                  diff = memcmp (a->text, b->text, (alen > blen) ? blen : alen);
                  if (!diff)
                  {
                    len_diff = (alen > blen)? 1 : ((alen < blen)? -1 : 0);
                    diff = len_diff;
                  }
                }
            }
        }
    }
  else
    {
      if (alen == 0)
        diff = - !!blen;
      else if (blen == 0)
        diff = 1;
      else
        {
          if (hard_LC_COLLATE)
            diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
          else
            {
              int len_diff;
              diff = memcmp (a->text, b->text, (alen > blen) ? blen : alen);
              if (!diff)
              {
                len_diff = (alen > blen)? 1 : ((alen < blen)? -1 : 0);
                diff = len_diff;
              }
            }
        }
    }

  return diff_reversed(diff, reverse);
}