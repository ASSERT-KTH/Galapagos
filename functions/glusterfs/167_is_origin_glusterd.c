is_origin_glusterd (dict_t *dict)
{
        gf_boolean_t  ret              = _gf_false;
        uuid_t        lock_owner       = {0,};
        uuid_t        *originator_uuid = NULL;

        GF_ASSERT (dict);

        ret = dict_get_bin (dict, "originator_uuid",
                            (void **) &originator_uuid);
        if (ret) {
                /* If not originator_uuid has been set, then the command
                 * has been originated from a glusterd running on older version
                 * Hence fetching the lock owner */
                ret = glusterd_get_lock_owner (&lock_owner);
                if (ret) {
                        ret = _gf_false;
                        goto out;
                }
                ret = !uuid_compare (MY_UUID, lock_owner);
        } else
                ret = !uuid_compare (MY_UUID, *originator_uuid);

out:
        return ret;
}