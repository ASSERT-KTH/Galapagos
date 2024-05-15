dict_set_dynstr_with_alloc (dict_t *this, char *key, const char *str)
{
        char *alloc_str = NULL;
        int   ret       = -1;

        alloc_str = gf_strdup (str);
        if (!alloc_str)
                return -1;

        ret = dict_set_dynstr (this, key, alloc_str);
        if (ret == -EINVAL)
                GF_FREE (alloc_str);

        return ret;
}