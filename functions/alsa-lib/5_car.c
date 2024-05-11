static inline struct alisp_object * car(struct alisp_object * p)
{
	if (alisp_compare_type(p, ALISP_OBJ_CONS))
		return p->value.c.car;

	return &alsa_lisp_nil;
}