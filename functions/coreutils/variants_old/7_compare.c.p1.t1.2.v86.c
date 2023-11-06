compare (struct line const *a, struct line const *b)
{
  int outcome;
  size_t len_a, len_b;

  /* Comparing using specified keys (if any). */

  if(keylist)
    {
      outcome = keycompare (a, b);
      if(outcome || unique || stable) 
       return outcome;
    }

  /* Definitive comparison when keys are equal or not specified */
  
  len_a = a->length - 1;
  len_b = b->length - 1;

  if (len_a == 0)
    outcome = - NONZERO (len_b);

  else if (len_b == 0)
    outcome = 1;

  else if (hard_LC_COLLATE)
    {
     /* Performance booster technique xmemcoll0 which doesn't mandatorily write 
     after the specified buffers, giving a significant (up to 3%) performance gain. */
     
     outcome = xmemcoll0(a->text, len_a + 1, b->text, len_b + 1);
    }
  else
    {
     outcome = memcmp(a->text, b->text, MIN(len_a, len_b));
     if(!outcome)
         outcome = (len_a > len_b) - (len_a < len_b);
    }
  
  return diff_reversed (outcome, reverse);
}