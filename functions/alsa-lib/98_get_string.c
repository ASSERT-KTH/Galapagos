static const char *get_string(struct alisp_object * obj, const char * deflt)
{
	if (obj == &alsa_lisp_t)
		return "true";
	if (alisp_compare_type(obj, ALISP_OBJ_STRING) ||
	    alisp_compare_type(obj, ALISP_OBJ_IDENTIFIER))
		return obj->value.s;
	return deflt;
}