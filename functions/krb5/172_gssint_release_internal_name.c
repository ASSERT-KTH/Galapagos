gssint_release_internal_name(OM_uint32 *minor_status, gss_OID mech_type,
			     gss_name_t *internal_name)
{
    OM_uint32		status;
    gss_mechanism	mech;

    mech = gssint_get_mechanism (mech_type);
    if (mech) {
	if (mech->gss_release_name) {
	    status = mech->gss_release_name (
					     minor_status,
					     internal_name);
	    if (status != GSS_S_COMPLETE)
		map_error(minor_status, mech);
	} else
	    status = GSS_S_UNAVAILABLE;

	return (status);
    }

    return (GSS_S_BAD_MECH);
}