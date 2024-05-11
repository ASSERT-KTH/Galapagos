static void delete_tree(struct alisp_instance *instance, struct alisp_object * p)
{
	if (p == NULL)
		return;
	if (alisp_compare_type(p, ALISP_OBJ_CONS)) {
		delete_tree(instance, p->value.c.car);
		delete_tree(instance, p->value.c.cdr);
	}
	delete_object(instance, p);
}