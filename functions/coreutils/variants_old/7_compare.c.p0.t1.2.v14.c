compare (struct line const *a, struct line const *b)
{
    int result;
    size_t lengthA, lengthB;

    /* First perform comparison based on the particular keys if any are available. 
       No keys are available only for plain sort and plain reverse sort. */
    if (keylist)
    {
        result = keycompare (a, b);
        if ((result != 0)||(unique)||(stable)) 
            return result;
    }

    /* If either keys are equal or no key was provided, the comparison depends on default criteria.  */
    lengthA = a->length - 1;
    lengthB = b->length - 1;

    if (lengthA == 0)
        result = - ((lengthB != 0) ? 1 : 0);
    else if (lengthB == 0)
        result = 1;
    else if (hard_LC_COLLATE)
    {
        /* xmemcoll0 is an optimized version that avoids definite setup of '\0' after the input buffers, contributing to performance improvements of up to 3% for brief lines.*/
        result = xmemcoll0 (a->text, lengthA + 1, b->text, lengthB + 1);
    }
    else
    {
        result = memcmp (a->text, b->text, (lengthA < lengthB) ? lengthA : lengthB);
        if (!result)
            result = (lengthA > lengthB ? 1 : (lengthA < lengthB ? -1 : 0));
    }

    return diff_reversed (result, reverse);
}