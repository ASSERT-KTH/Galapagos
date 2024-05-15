nfs3_request_xlator_deviceid (rpcsvc_request_t *rq)
{
        struct nfs3_state       *nfs3 = NULL;
        xlator_t                *xl = NULL;
        uint64_t                devid = 0;
        uuid_t                  volumeid = {0, };

        if (!rq)
                return 0;

        xl = rpcsvc_request_private (rq);
        nfs3 = rpcsvc_request_program_private (rq);
        if (gf_nfs_dvm_off (nfs_state (nfs3->nfsx)))
                devid = (uint64_t)nfs_xlator_to_xlid (nfs3->exportslist, xl);
        else {
                __nfs3_get_volume_id (nfs3, xl, volumeid);
                memcpy (&devid, &volumeid[8], sizeof (devid));
        }

        return devid;
}