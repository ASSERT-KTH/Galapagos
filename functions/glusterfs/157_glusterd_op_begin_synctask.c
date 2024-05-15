glusterd_op_begin_synctask (rpcsvc_request_t *req, glusterd_op_t op,
                            void *dict)
{
        int              ret = 0;

        ret = dict_set_int32 (dict, GD_SYNC_OPCODE_KEY, op);
        if (ret) {
                gf_log (THIS->name, GF_LOG_ERROR,
                        "dict set failed for setting operations");
                goto out;
        }

        gd_sync_task_begin (dict, req);
        ret = 0;
out:

        return ret;
}