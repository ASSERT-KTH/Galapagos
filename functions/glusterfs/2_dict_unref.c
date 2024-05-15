dict_unref (dict_t *this)
{
        int32_t ref;

        if (!this) {
                gf_log_callingfn ("dict", GF_LOG_WARNING, "dict is NULL");
                return;
        }

        LOCK (&this->lock);

        this->refcount--;
        ref = this->refcount;

        UNLOCK (&this->lock);

        if (!ref)
                dict_destroy (this);
}