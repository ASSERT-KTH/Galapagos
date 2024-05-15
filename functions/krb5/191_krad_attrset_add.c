krad_attrset_add(krad_attrset *set, krad_attr type, const krb5_data *data)
{
    krb5_error_code retval;
    attr *tmp;

    retval = kr_attr_valid(type, data);
    if (retval != 0)
        return retval;

    tmp = calloc(1, sizeof(attr));
    if (tmp == NULL)
        return ENOMEM;

    tmp->type = type;
    tmp->attr = make_data(tmp->buffer, data->length);
    memcpy(tmp->attr.data, data->data, data->length);

    K5_TAILQ_INSERT_TAIL(&set->list, tmp, list);
    return 0;
}