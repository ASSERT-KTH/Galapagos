static struct alisp_object * eval(struct alisp_instance *instance, struct alisp_object * p)
{
	switch (alisp_get_type(p)) {
	case ALISP_OBJ_IDENTIFIER: {
		struct alisp_object *r = incref_tree(instance, get_object(instance, p));
		delete_object(instance, p);
		return r;
	}
	case ALISP_OBJ_INTEGER:
	case ALISP_OBJ_FLOAT:
	case ALISP_OBJ_STRING:
	case ALISP_OBJ_POINTER:
		return p;
	case ALISP_OBJ_CONS:
		return eval_cons(instance, p);
	default:
		break;
	}

	return p;
}