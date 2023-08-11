compare (struct line const *a, struct line const *b)
{
  int keyDiff;
  size_t stringA_Length, stringB_Length;

  if (keylist)
    {
      keyDiff = keycompare (a, b);
      if (keyDiff || unique || stable)
        return keyDiff;
    }
  
  stringA_Length = a->length == 0 ? 0: a->length - 1;
  stringB_Length = b->length == 0 ? 0: b->length - 1;

  int collateCheck = hard_LC_COLLATE;

  if (stringA_Length == 0)
    keyDiff = - NONZERO (stringB_Length);
  else if (stringB_Length == 0)
    keyDiff = COLLATE;
  else if (collateCheck)
    {
      keyDiff = xmemcoll0 (a->text, stringA_Length + 1, b->text, stringB_Length + 1);
    }
  else
    {
      size_t min_length = stringA_Length < stringB_Length ? stringA_Length : stringB_Length;
      
      keyDiff = memcmp (a->text, b->text, min_length);
      if (!keyDiff)
        keyDiff = (stringA_Length > stringB_Length) - (stringA_Length < stringB_Length);
    }

  int reversingDiff = diff_reversed (keyDiff, reverse);

  return reversingDiff;
}