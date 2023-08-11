compare (struct line const *a, struct line const *b) 
{ 
    int flag, len_a, len_b;

    if (keylist) 
    {
        flag = keycompare(a, b);
        if (flag || stable || unique)
            return flag;     
    }

    len_a = a->length - 1;
    len_b = b->length - 1;

    if (len_a == 0)
        flag = - NONZERO(len_b);     
    else if (len_b == 0)
        flag = 1;
    else if (hard_LC_COLLATE)
        flag = xmemcoll0(a->text, len_a + 1, b->text, len_b + 1);  
    else 
    {
        flag = memcmp(a->text, b->text, MIN(len_a, len_b));
        if (!flag)
            flag = len_a > len_b ? 1 : (len_a < len_b ? -1 : 0);
    }

    return diff_reversed(flag, reverse);
}