static int do_cmp_if_stats(struct csp_cmp_message *cmp) {

	csp_iface_t *ifc = csp_iflist_get_by_name(cmp->if_stats.interface);
	if (ifc == NULL)
		return CSP_ERR_INVAL;

	cmp->if_stats.tx =       csp_hton32(ifc->tx);
	cmp->if_stats.rx =       csp_hton32(ifc->rx);
	cmp->if_stats.tx_error = csp_hton32(ifc->tx_error);
	cmp->if_stats.rx_error = csp_hton32(ifc->rx_error);
	cmp->if_stats.drop =     csp_hton32(ifc->drop);
	cmp->if_stats.autherr =  csp_hton32(ifc->autherr);
	cmp->if_stats.frame =    csp_hton32(ifc->frame);
	cmp->if_stats.txbytes =  csp_hton32(ifc->txbytes);
	cmp->if_stats.rxbytes =  csp_hton32(ifc->rxbytes);
	cmp->if_stats.irq = 	 csp_hton32(ifc->irq);

	return CSP_ERR_NONE;
}