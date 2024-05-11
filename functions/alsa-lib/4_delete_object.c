static void delete_object(struct alisp_instance *instance, struct alisp_object * p)
{
	if (p == NULL || p == &alsa_lisp_nil || p == &alsa_lisp_t)
		return;
	if (alisp_compare_type(p, ALISP_OBJ_NIL) ||
	    alisp_compare_type(p, ALISP_OBJ_T))
		return;
	assert(alisp_get_refs(p) > 0);
	lisp_debug(instance, "delete cons %p (type = %i, refs = %i) (s = '%s')", p, alisp_get_type(p), alisp_get_refs(p),
			alisp_compare_type(p, ALISP_OBJ_STRING) ||
			alisp_compare_type(p, ALISP_OBJ_IDENTIFIER) ? p->value.s : "???");
	if (alisp_dec_refs(p))
		return;
	list_del(&p->list);
	instance->used_objs--;
	free_object(p);
	if (instance->free_objs >= ALISP_FREE_OBJ_POOL) {
		lisp_debug(instance, "freed cons %p", p);
		free(p);
		return;
	}
	lisp_debug(instance, "moved cons %p to free list", p);
	list_add(&p->list, &instance->free_objs_list);
	instance->free_objs++;
}