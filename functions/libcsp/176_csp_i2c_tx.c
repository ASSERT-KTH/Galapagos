int csp_i2c_tx(const csp_route_t * ifroute, csp_packet_t * packet) {

	/* Cast the CSP packet buffer into an i2c frame */
	csp_i2c_frame_t * frame = (csp_i2c_frame_t *) packet;

	/* Insert destination node into the i2c destination field */
	frame->dest = (ifroute->via != CSP_NO_VIA_ADDRESS) ? ifroute->via : packet->id.dst;

	/* Save the outgoing id in the buffer */
	packet->id.ext = csp_hton32(packet->id.ext);

	/* Add the CSP header to the I2C length field */
	frame->len += sizeof(packet->id);
	frame->len_rx = 0;

	/* Some I2C drivers support X number of retries
	 * CSP don't care about this. If it doesn't work the first
	 * time, don't use time on it.
	 */
	frame->retries = 0;

	/* send frame */
        csp_i2c_interface_data_t * ifdata = ifroute->iface->interface_data;
	return (ifdata->tx_func)(ifroute->iface->driver_data, frame);

}