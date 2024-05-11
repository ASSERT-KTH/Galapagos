add_to_strlist( strlist_t *list, const char *string )
{
    strlist_t sl;

    sl = xmalloc( sizeof *sl + strlen(string));
    sl->flags = 0;
    strcpy(sl->d, string);
    sl->next = *list;
    *list = sl;
    return sl;
}