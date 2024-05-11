int snd_config_add(snd_config_t *parent, snd_config_t *child)
{
	snd_config_iterator_t i, next;
	assert(parent && child);
	if (!child->id || child->parent)
		return -EINVAL;
	snd_config_for_each(i, next, parent) {
		snd_config_t *n = snd_config_iterator_entry(i);
		if (strcmp(child->id, n->id) == 0)
			return -EEXIST;
	}
	child->parent = parent;
	list_add_tail(&child->list, &parent->u.compound.fields);
	return 0;
}