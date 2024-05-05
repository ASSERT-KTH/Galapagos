static int do_cmp_ident(struct csp_cmp_message *cmp) {

	/* Copy revision */
	strncpy(cmp->ident.revision, csp_conf.revision, CSP_CMP_IDENT_REV_LEN);
	cmp->ident.revision[CSP_CMP_IDENT_REV_LEN - 1] = '\0';

	/* Copy compilation date */
	strncpy(cmp->ident.date, __DATE__, CSP_CMP_IDENT_DATE_LEN);
	cmp->ident.date[CSP_CMP_IDENT_DATE_LEN - 1] = '\0';

	/* Copy compilation time */
	strncpy(cmp->ident.time, __TIME__, CSP_CMP_IDENT_TIME_LEN);
	cmp->ident.time[CSP_CMP_IDENT_TIME_LEN - 1] = '\0';

	/* Copy hostname */
	strncpy(cmp->ident.hostname, csp_conf.hostname, CSP_HOSTNAME_LEN);
	cmp->ident.hostname[CSP_HOSTNAME_LEN - 1] = '\0';

	/* Copy model name */
	strncpy(cmp->ident.model, csp_conf.model, CSP_MODEL_LEN);
	cmp->ident.model[CSP_MODEL_LEN - 1] = '\0';

	return CSP_ERR_NONE;

}