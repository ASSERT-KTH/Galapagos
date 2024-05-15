dict_copy_with_ref (dict_t *dict,
                    dict_t *new)
{
        dict_t *local_new = NULL;

        GF_VALIDATE_OR_GOTO("dict", dict, fail);

        if (new == NULL) {
                local_new = dict_new ();
                GF_VALIDATE_OR_GOTO("dict", local_new, fail);
                new = local_new;
        }

        dict_foreach (dict, _copy, new);
fail:
        return new;
}