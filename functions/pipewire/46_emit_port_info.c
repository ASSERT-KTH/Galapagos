static void emit_port_info(struct impl *this, struct port *port, bool full)
{
	uint64_t old = full ? port->info.change_mask : 0;
	if (full)
		port->info.change_mask = port->info_all;
	if (port->info.change_mask) {
		char* aliases[2];
		int n_aliases, n_items;

		aliases[0] = alloca(jack_port_name_size());
		aliases[1] = alloca(jack_port_name_size());
		n_aliases = jack_port_get_aliases(port->jack_port, aliases);
		n_items = 1;
		port->items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_PORT_NAME,
				jack_port_short_name(port->jack_port));
		if (n_aliases > 0)
			port->items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_OBJECT_PATH, aliases[0]);
		if (n_aliases > 1)
			port->items[n_items++] = SPA_DICT_ITEM_INIT(SPA_KEY_PORT_ALIAS, aliases[1]);
		port->props = SPA_DICT_INIT(port->items, n_items);

		spa_node_emit_port_info(&this->hooks,
				SPA_DIRECTION_INPUT, port->id, &port->info);

		port->info.change_mask = old;
	}
}