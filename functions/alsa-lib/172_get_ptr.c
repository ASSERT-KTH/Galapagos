static const void *get_ptr(struct alisp_instance * instance,
			   struct alisp_object * obj,
			   const char *_ptr_id)
{
	const char *ptr_id;
	const void *ptr;
	
	ptr_id = get_string(car(obj), NULL);
	if (ptr_id == NULL) {
		delete_tree(instance, obj);
		return NULL;
	}
	if (strcmp(ptr_id, _ptr_id)) {
		delete_tree(instance, obj);
		return NULL;
	}
	ptr = get_pointer(cdr(obj));
	delete_tree(instance, obj);
	return ptr;
}