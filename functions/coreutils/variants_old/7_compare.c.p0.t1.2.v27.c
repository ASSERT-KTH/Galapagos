compare (struct line const *a, struct line const *b)
{
  int diff;
  size_t alen, blen;

  // Checking if any sort key has been provided
  if (keylist!=NULL)
  {
    diff = keycompare(a,b); 

    // Returning the difference, if any
    if(diff || unique || stable)
    {
      return diff;
    }
  }
    
  // Default: comparison based on length
  alen = a->length - 1; 
  blen = b->length - 1;

  if(alen == 0 && blen !=0)
    diff = -1;
  else if(blen == 0 && alen !=0)
    diff = 1;
  else if(alen == 0 && blen ==0 )
    diff = 0;
  else if(hard_LC_COLLATE)
  {
    // For locale's encoding
    diff = xmemcoll0(a->text, alen + 1, b->text, blen + 1);
  }
  else 
  {
    // Comparing them lexicographically on their common lengths
    diff = memcmp(a->text, b->text, (alen<blen?alen:blen));
 
    // In case of equal lengths and equal texts, return 0
    if(!diff && alen == blen) 
        diff = 0;
    
    // If length are not equal but texts are, sort on the basis of length
    if(!diff && alen!=blen)     
        diff = alen - blen > 0 ? 1 : -1;
  }
  
  // Adjust it based on the sort order is ascending or descending.
  return diff_reversed(diff, (reverse!=0));
}