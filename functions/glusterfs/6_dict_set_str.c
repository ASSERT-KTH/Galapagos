dict_set_str (dict_t *this, char *key, char *str)
{
        data_t * data = NULL;
        int      ret  = 0;

        data = str_to_data (str);
        if (!data) {
                ret = -EINVAL;
                goto err;
        }

        ret = dict_set (this, key, data);
        if (ret < 0)
                data_destroy (data);

err:
        return ret;
}