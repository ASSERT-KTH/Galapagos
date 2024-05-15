glusterd_op_sm_inject_event (glusterd_op_sm_event_type_t event_type,
                             uuid_t *txn_id, void *ctx)
{
        int32_t                 ret = -1;
        glusterd_op_sm_event_t  *event = NULL;

        GF_ASSERT (event_type < GD_OP_EVENT_MAX &&
                        event_type >= GD_OP_EVENT_NONE);

        ret = glusterd_op_sm_new_event (event_type, &event);

        if (ret)
                goto out;

        event->ctx = ctx;

        if (txn_id)
                uuid_copy (event->txn_id, *txn_id);

        gf_log (THIS->name, GF_LOG_DEBUG, "Enqueue event: '%s'",
                glusterd_op_sm_event_name_get (event->event));
        list_add_tail (&event->list, &gd_op_sm_queue);

out:
        return ret;
}