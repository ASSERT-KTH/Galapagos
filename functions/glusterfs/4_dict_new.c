dict_new (void)
{
        dict_t *dict = NULL;

        dict = get_new_dict_full(1);

        if (dict)
                dict_ref (dict);

        return dict;
}