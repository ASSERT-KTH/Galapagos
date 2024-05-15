dict_set_static_bin (dict_t *this, char *key, void *ptr, size_t size)
{
        data_t * data = NULL;
        int      ret  = 0;

        if (!ptr || (size > ULONG_MAX)) {
                ret = -EINVAL;
                goto err;
        }

        data = bin_to_data (ptr, size);
        if (!data) {
                ret = -EINVAL;
                goto err;
        }

        data->data = ptr;
        data->len  = size;
        data->is_static = 1;

        ret = dict_set (this, key, data);
        if (ret < 0)
                data_destroy (data);

err:
        return ret;
}