dict_copy (dict_t *dict,
           dict_t *new)
{
        if (!dict) {
                gf_log_callingfn ("dict", GF_LOG_WARNING, "dict is NULL");
                return NULL;
        }

        if (!new)
                new = get_new_dict_full (dict->hash_size);

        dict_foreach (dict, _copy, new);

        return new;
}