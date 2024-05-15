dict_get_str_boolean (dict_t *this, char *key, int default_val)
{
        data_t       *data = NULL;
        gf_boolean_t  boo = _gf_false;
        int           ret  = 0;

        ret = dict_get_with_ref (this, key, &data);
        if (ret < 0) {
                if (ret == -ENOENT)
                        ret = default_val;
                else
                        ret = -1;
                goto err;
        }

        GF_ASSERT (data);

        if (!data->data) {
                ret = -1;
                goto err;
        }

        ret = gf_string2boolean (data->data, &boo);
        if (ret == -1)
                goto err;

        ret = boo;

err:
        if (data)
                data_unref (data);

        return ret;
}