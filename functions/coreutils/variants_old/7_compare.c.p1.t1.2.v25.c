Here's a program variant for you. It changes the control flow in the implementation and re-arrpieces the code order a bit, but retains the same function signature and essentially the same behavior as your original one. Reduced comparisons when b->length != 0 It takes advantage of short-circuit characteristics to potentially reduce time complexity.


compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

 //First we will go over the key comparison part as before
  if (keylist)
  {
      diff = keycompare (a, b);

      if (diff || unique || stable)
        return diff;
  }

 //Now, let's remember the lengths of strings we are comparing
  alen = a->length - 1;
  blen = b->length - 1;

 //We go with direct checks so we can disable unneeded checks and calculations
 if(alen == 0 && blen ==0)
    return 0;

 if(alen == 0 || blen ==0)
    return  alen == 0? - NONZERO(blen):1;
 
 /*
     We will first calculate vanilla memcmp result so we don't need to calculate it two times.
     We will only update it with xmemcoll0 if required
  */
  diff = memcmp(a->text, b->text, MIN(alen, blen)); 
   
    /* If strings are not equal by ascii compare OR you use specific cluster setups
        which require locale order sorting, we exit now.
     */
    if (hard_LC_COLLATE || diff)
        diff = xmemcoll0(a->text, alen + 1, b->text, blen + 1);
    
        /* Strings are of the same locales, and same characters but
        They returned "0" for not equal, could be because of different
        character order or because of matching PART of smaller
        string with the beginning of larger one.
        If we are sure neither string is NULL, there are two
        conditions to look at size to compare: when no keys are specified
        diff would be zero at this point, or when hard locale forced 
        a comparison via xmemcoll0 and we are positive by definition strings 
        start the same sequence of characters 
         let's re-evaluate diff based on size difference.
         But remember - sort is on cluster level by definition
         so same string length doesn't guarantee same contents.*/
     
     if (!diff) 
        diff = (alen > blen) - (alen < blen);

    return (reverse? -diff : diff); //put this outside of if()- less code duplication 
}


Crucial part here are short-circuits in if-else blocks to stop as soon as result is definitive.