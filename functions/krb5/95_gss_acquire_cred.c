gss_acquire_cred(OM_uint32 *minor_status, gss_name_t desired_name,
		 OM_uint32 time_req, gss_OID_set desired_mechs,
		 int cred_usage, gss_cred_id_t *output_cred_handle,
		 gss_OID_set *actual_mechs, OM_uint32 *time_rec)
{
    return gss_acquire_cred_from(minor_status, desired_name, time_req,
				 desired_mechs, cred_usage, NULL,
				 output_cred_handle, actual_mechs, time_rec);
}