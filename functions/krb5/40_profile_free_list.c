void KRB5_CALLCONV profile_free_list(char **list)
{
    char        **cp;

    if (list == 0)
        return;

    for (cp = list; *cp; cp++)
        free(*cp);
    free(list);
}