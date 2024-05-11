static void reset_props(struct props *props)
{
	snprintf(props->ifname, sizeof(props->ifname), "%s", DEFAULT_IFNAME);
	parse_addr(props->addr, DEFAULT_ADDR);
	props->prio = DEFAULT_PRIO;
	parse_streamid(&props->streamid, DEFAULT_STREAMID);
	props->mtt = DEFAULT_MTT;
	props->t_uncertainty = DEFAULT_TU;
	props->frames_per_pdu = DEFAULT_FRAMES_PER_PDU;
}