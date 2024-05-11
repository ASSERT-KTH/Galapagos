static struct alisp_object * new_float(struct alisp_instance *instance, double value)
{
	struct alisp_object * obj;
	
	obj = search_object_float(instance, value);
	if (obj != NULL)
		return obj;
	obj = new_object(instance, ALISP_OBJ_FLOAT);
	if (obj) {
		list_add(&obj->list, &instance->used_objs_list[(long)value & ALISP_OBJ_PAIR_HASH_MASK][ALISP_OBJ_FLOAT]);
		obj->value.f = value;
	}
	return obj;
}