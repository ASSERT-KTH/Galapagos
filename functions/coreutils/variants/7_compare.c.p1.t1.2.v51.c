int compare (struct line const *a, struct line const *b)
{
   int diff_difference;
   size_t sizeA, sizeB;

   if (keylist)
   {
       diff_difference = keycompare (a, b);
       if (diff_difference || unique || stable)
           return diff_difference;
   }

   sizeA = a->length - 1, 
   sizeB = b->length - 1;

   if (sizeA == 0)
       diff_difference = - NONZERO (sizeB);
   else if (sizeB == 0)
       diff_difference = 1;
   else if (hard_LC_COLLATE)
   {
       diff_difference = xmemcoll0 (a->text, sizeA + 1, b->text, sizeB + 1);
   }
   else
   {
       diff_difference = memcmp (a->text, b->text, MIN (sizeA, sizeB));
       if (!diff_difference)
           diff_difference = (sizeA > sizeB) - (sizeA < sizeB);
   }

   return diff_reversed (diff_difference, reverse);
}