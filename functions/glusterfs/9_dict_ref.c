dict_ref (dict_t *this)
{
        if (!this) {
                gf_log_callingfn ("dict", GF_LOG_WARNING, "dict is NULL");
                return NULL;
        }

        LOCK (&this->lock);

        this->refcount++;

        UNLOCK (&this->lock);

        return this;
}