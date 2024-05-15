dict_destroy (dict_t *this)
{
        if (!this) {
                gf_log_callingfn ("dict", GF_LOG_WARNING, "dict is NULL");
                return;
        }

        data_pair_t *pair = this->members_list;
        data_pair_t *prev = this->members_list;

        LOCK_DESTROY (&this->lock);

        while (prev) {
                pair = pair->next;
                data_unref (prev->value);
                GF_FREE (prev->key);
                if (prev != &this->free_pair) {
                        mem_put (prev);
                }
                prev = pair;
        }

        if (this->members != &this->members_internal) {
                mem_put (this->members);
        }

        GF_FREE (this->extra_free);
        free (this->extra_stdfree);

        if (!this->is_static)
                mem_put (this);

        return;
}