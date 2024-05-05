int csp_cmp(uint8_t node, uint32_t timeout, uint8_t code, int msg_size, struct csp_cmp_message * msg) {
	msg->type = CSP_CMP_REQUEST;
	msg->code = code;
	int status = csp_transaction(CSP_PRIO_NORM, node, CSP_CMP, timeout, msg, msg_size, msg, msg_size);
	if (status == 0) {
		return CSP_ERR_TIMEDOUT;
	}

	return CSP_ERR_NONE;
}