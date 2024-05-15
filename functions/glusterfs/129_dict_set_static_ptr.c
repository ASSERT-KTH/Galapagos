dict_set_static_ptr (dict_t *this, char *key, void *ptr)
{
        data_t * data = NULL;
        int      ret  = 0;

        data = data_from_static_ptr (ptr);
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