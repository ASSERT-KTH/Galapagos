free_strlist( strlist_t sl )
{
    strlist_t sl2;

    for(; sl; sl = sl2 ) {
	sl2 = sl->next;
	xfree(sl);
    }
}