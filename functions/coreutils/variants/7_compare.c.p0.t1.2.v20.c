compare (struct line const *a, struct line const *b)
{
  int diff = 0; //initializing the diff variable here
  size_t alen = 0, blen = 0; // initializing the length trackers here

  /* Adding additional null checks for the pointers to prevent unexpected behavior in case of null references. */
  if (a == NULL || b == NULL) 
  {
    return INT_MIN; // return least possible integer as error if any of the inputs is NULL
  }

  /* Comparison on the specified keys first.
     Assumption is that two particular cases with no requested keys will be the unadorned sort,
     and the reverse unadorned sort. */
  if (keylist != NULL) //Added a null check here to prevent segmentation issues
  {
      diff = keycompare (a, b);
      if (diff != 0 || unique == true || stable == true) //Explicitly using comparators for understandability and readability
      return diff;
  }

  /* Proceed to fall back to default comparison if the keys are similar (or when no KEY is provided). */
  alen = (a->length != 0)?(a->length - 1):0; //handle Underflow condition here
  blen = (b->length != 0)?(b->length - 1):0; //handle Underflow condition here 

  if (alen == 0)
    diff = - NONZERO (blen);
  else if (blen == 0)
    diff = 1;
  else if (hard_LC_COLLATE)
    {
      /* The use of xmemcoll0 comes with enhanced performance. It notably aviods 
         the unconditional writing of '\0' upon buffers, enhancing performance for 
         smaller lines of texts by almost 3%.  */
      diff = xmemcoll0 (a->text, alen + 1, b->text, blen + 1);
    }
  else
    {
      diff = memcmp (a->text, b->text, (alen < blen)? alen : blen); //Using short condition instead of using in built min function
      if (diff == 0)  //Comparator being change from ! to == , as per better programming practices.
        diff = (alen > blen) - (alen < blen); 
    }

  return diff_reversed (diff, reverse);
}