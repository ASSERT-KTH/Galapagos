dict_get (dict_t *this, char *key)
{
        data_pair_t *pair;

        if (!this || !key) {
                gf_log_callingfn ("dict", GF_LOG_INFO,
                                  "!this || key=%s", (key) ? key : "()");
                return NULL;
        }

        LOCK (&this->lock);

        pair = _dict_lookup (this, key);

        UNLOCK (&this->lock);

        if (pair)
                return pair->value;

        return NULL;
}