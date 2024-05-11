static struct alisp_object * new_integer(struct alisp_instance *instance, long value)
{
	struct alisp_object * obj;
	
	obj = search_object_integer(instance, value);
	if (obj != NULL)
		return obj;
	obj = new_object(instance, ALISP_OBJ_INTEGER);
	if (obj) {
		list_add(&obj->list, &instance->used_objs_list[value & ALISP_OBJ_PAIR_HASH_MASK][ALISP_OBJ_INTEGER]);
		obj->value.i = value;
	}
	return obj;
}