log_status(char *m, OM_uint32 maj_stat, OM_uint32 min_stat)
{
	OM_uint32 min, msg_ctx;
	gss_buffer_desc msgg, msgm;

	msg_ctx = 0;
	gss_display_status(&min, maj_stat, GSS_C_GSS_CODE, GSS_C_NULL_OID,
			   &msg_ctx, &msgg);
	msg_ctx = 0;
	gss_display_status(&min, min_stat, GSS_C_MECH_CODE, GSS_C_NULL_OID,
			   &msg_ctx, &msgm);

	log_debug("%s: %.*s - %.*s\n", m,
		  msgg.length, (char *)msgg.value,
		  msgm.length, (char *)msgm.value);

	gss_release_buffer(&min, &msgg);
	gss_release_buffer(&min, &msgm);
}