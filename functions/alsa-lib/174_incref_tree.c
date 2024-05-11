static struct alisp_object * incref_tree(struct alisp_instance *instance, struct alisp_object * p)
{
	if (p == NULL)
		return NULL;
	if (alisp_compare_type(p, ALISP_OBJ_CONS)) {
		incref_tree(instance, p->value.c.car);
		incref_tree(instance, p->value.c.cdr);
	}
	return incref_object(instance, p);
}