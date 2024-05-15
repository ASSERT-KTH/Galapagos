update_stat (struct iatt *stbuf,
	     struct gf_filter *filter)
{
	int32_t idx = 0;
	for (idx = 0; idx < filter->translate_num_uid_entries; idx++) {
		if (stbuf->ia_uid == GF_FILTER_ROOT_UID)
			continue;
		if ((stbuf->ia_uid >= filter->translate_input_uid[idx][0]) &&
		    (stbuf->ia_uid <= filter->translate_input_uid[idx][1])) {
			stbuf->ia_uid = filter->translate_output_uid[idx];
			break;
		}
	}
	
	for (idx = 0; idx < filter->translate_num_gid_entries; idx++) {
		if (stbuf->ia_gid == GF_FILTER_ROOT_GID)
			continue;
		if ((stbuf->ia_gid >= filter->translate_input_gid[idx][0]) &&
		    (stbuf->ia_gid <= filter->translate_input_gid[idx][1])) {
			stbuf->ia_gid = filter->translate_output_gid[idx];
			break;
		}
	}

	if (filter->fixed_uid_set) {
		stbuf->ia_uid = filter->fixed_uid;
	}

	if (filter->fixed_gid_set) {
		stbuf->ia_gid = filter->fixed_gid;
	}
	
	return 0;
}