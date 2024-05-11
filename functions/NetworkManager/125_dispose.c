dispose(GObject *object)
{
    NMActRequest                 *self = NM_ACT_REQUEST(object);
    NMActRequestPrivate          *priv = NM_ACT_REQUEST_GET_PRIVATE(self);
    NMActRequestGetSecretsCallId *call_id, *call_id_safe;

    /* Kill any in-progress secrets requests */
    c_list_for_each_entry_safe (call_id, call_id_safe, &priv->call_ids_lst_head, call_ids_lst)
        _do_cancel_secrets(self, call_id, TRUE);

    G_OBJECT_CLASS(nm_act_request_parent_class)->dispose(object);
}