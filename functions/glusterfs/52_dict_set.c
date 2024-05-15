dict_set (dict_t *this,
          char *key,
          data_t *value)
{
        int32_t ret;

        if (!this || !value) {
                gf_log_callingfn ("dict", GF_LOG_WARNING,
                                  "!this || !value for key=%s", key);
                return -1;
        }

        LOCK (&this->lock);

        ret = _dict_set (this, key, value, 1);

        UNLOCK (&this->lock);

        return ret;
}