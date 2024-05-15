gss_add_oid_set_member(OM_uint32 *minor_status, gss_OID member_oid,
		       gss_OID_set *oid_set)
{
    OM_uint32 status;
    status = generic_gss_add_oid_set_member(minor_status, member_oid, oid_set);
    if (status != GSS_S_COMPLETE)
	map_errcode(minor_status);
    return status;
}