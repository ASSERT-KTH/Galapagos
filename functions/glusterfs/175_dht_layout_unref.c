dht_layout_unref (xlator_t *this, dht_layout_t *layout)
{
        dht_conf_t  *conf = NULL;
        int          ref = 0;

        if (!layout || layout->preset || !this->private)
                return;

        conf = this->private;

        LOCK (&conf->layout_lock);
        {
                ref = --layout->ref;
        }
        UNLOCK (&conf->layout_lock);

        if (!ref)
                GF_FREE (layout);
}