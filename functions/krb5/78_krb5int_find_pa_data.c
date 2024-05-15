krb5int_find_pa_data(krb5_context context, krb5_pa_data *const *pa_list,
                     krb5_preauthtype pa_type)
{
    krb5_pa_data *const *pa;

    for (pa = pa_list; pa != NULL && *pa != NULL; pa++) {
        if ((*pa)->pa_type == pa_type)
            return *pa;
    }
    return NULL;
}