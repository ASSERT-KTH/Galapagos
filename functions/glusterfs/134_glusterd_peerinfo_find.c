glusterd_peerinfo_find (uuid_t uuid, const char *hostname)
{
        glusterd_peerinfo_t *peerinfo = NULL;
        xlator_t            *this     = NULL;

        this = THIS;
        GF_ASSERT (this);


        if (uuid) {
                peerinfo = glusterd_peerinfo_find_by_uuid (uuid);

                if (peerinfo) {
                        return peerinfo;
                } else {
                        gf_log (this->name, GF_LOG_DEBUG,
                                 "Unable to find peer by uuid: %s",
                                 uuid_utoa (uuid));
                }

        }

        if (hostname) {
                peerinfo = glusterd_peerinfo_find_by_hostname (hostname);

                if (peerinfo) {
                        return peerinfo;
                } else {
                        gf_log (this->name, GF_LOG_DEBUG,
                                "Unable to find hostname: %s", hostname);
                }
        }
        return NULL;
}