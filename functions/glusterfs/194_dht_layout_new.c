dht_layout_new (xlator_t *this, int cnt)
{
        dht_layout_t *layout = NULL;
        dht_conf_t   *conf = NULL;

        REQUIRE(NULL != this);
        REQUIRE(cnt >= 0);

        conf = this->private;

        layout = GF_CALLOC (1, layout_size (cnt),
                            gf_dht_mt_dht_layout_t);
        if (!layout) {
                goto out;
        }

        layout->type = DHT_HASH_TYPE_DM;
        layout->cnt = cnt;

        if (conf) {
                layout->spread_cnt = conf->dir_spread_cnt;
                layout->gen = conf->gen;
        }

        layout->ref = 1;

        ENSURE(NULL != layout);
        ENSURE(layout->type == DHT_HASH_TYPE_DM);
        ENSURE(layout->cnt == cnt);
        ENSURE(layout->ref == 1);
out:
        return layout;
}