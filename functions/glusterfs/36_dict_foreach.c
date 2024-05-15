dict_foreach (dict_t *dict,
              int (*fn)(dict_t *this,
                        char *key,
                        data_t *value,
                        void *data),
              void *data)
{
        int     ret = 0;

        ret = dict_foreach_match (dict, match_everything, NULL, fn, data);

        if (ret > 0)
                ret = 0;

        return ret;
}