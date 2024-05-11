static struct alisp_object * new_object(struct alisp_instance *instance, int type)
{
	struct alisp_object * p;

	if (list_empty(&instance->free_objs_list)) {
		p = (struct alisp_object *)malloc(sizeof(struct alisp_object));
		if (p == NULL) {
			nomem();
			return NULL;
		}
		lisp_debug(instance, "allocating cons %p", p);
	} else {
		p = (struct alisp_object *)instance->free_objs_list.next;
		list_del(&p->list);
		instance->free_objs--;
		lisp_debug(instance, "recycling cons %p", p);
	}

	instance->used_objs++;

	alisp_set_type(p, type);
	alisp_set_refs(p, 1);
	if (type == ALISP_OBJ_CONS) {
		p->value.c.car = &alsa_lisp_nil;
		p->value.c.cdr = &alsa_lisp_nil;
		list_add(&p->list, &instance->used_objs_list[0][ALISP_OBJ_CONS]);
	}

	if (instance->used_objs + instance->free_objs > instance->max_objs)
		instance->max_objs = instance->used_objs + instance->free_objs;

	return p;
}