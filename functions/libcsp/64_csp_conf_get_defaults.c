static inline void csp_conf_get_defaults(csp_conf_t * conf) {
	conf->address = 1;
	conf->hostname = "hostname";
	conf->model = "model";
	conf->revision = "revision";
	conf->conn_max = 10;
	conf->conn_queue_length = 10;
	conf->fifo_length = 25;
	conf->port_max_bind = 24;
	conf->rdp_max_window = 20;
	conf->buffers = 10;
	conf->buffer_data_size = 256;
	conf->conn_dfl_so = CSP_O_NONE;
}