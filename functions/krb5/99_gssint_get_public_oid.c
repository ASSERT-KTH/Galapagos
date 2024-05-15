gssint_get_public_oid(gss_const_OID oid)
{
	gss_mech_info minfo;
	gss_OID public_oid = GSS_C_NO_OID;

	/* if oid is null -> then get default which is the first in the list */
	if (oid == GSS_C_NO_OID)
		return GSS_C_NO_OID;

	if (gssint_mechglue_initialize_library() != 0)
		return GSS_C_NO_OID;

	k5_mutex_lock(&g_mechListLock);

	for (minfo = g_mechList; minfo != NULL; minfo = minfo->next) {
		if (minfo->is_interposer)
			continue;
		if (g_OID_equal(minfo->mech_type, oid) ||
		    ((minfo->int_mech_type != GSS_C_NO_OID) &&
		     (g_OID_equal(minfo->int_mech_type, oid)))) {
			public_oid = minfo->mech_type;
			break;
		}
	}

	k5_mutex_unlock(&g_mechListLock);
	return public_oid;
}