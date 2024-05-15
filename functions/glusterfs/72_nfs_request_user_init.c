nfs_request_user_init (nfs_user_t *nfu, rpcsvc_request_t *req)
{
        gid_t           *gidarr = NULL;
        int             gids = 0;

        if ((!req) || (!nfu))
                return;

        gidarr = rpcsvc_auth_unix_auxgids (req, &gids);
        nfs_user_create (nfu, rpcsvc_request_uid (req),
                         rpcsvc_request_gid (req), gidarr, gids);

        return;
}