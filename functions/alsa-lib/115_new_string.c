static struct alisp_object * new_string(struct alisp_instance *instance, const char *str)
{
	struct alisp_object * obj;
	
	obj = search_object_string(instance, str);
	if (obj != NULL)
		return obj;
	obj = new_object(instance, ALISP_OBJ_STRING);
	if (obj)
		list_add(&obj->list, &instance->used_objs_list[get_string_hash(str)][ALISP_OBJ_STRING]);
	if (obj && (obj->value.s = strdup(str)) == NULL) {
		delete_object(instance, obj);
		nomem();
		return NULL;
	}
	return obj;
}