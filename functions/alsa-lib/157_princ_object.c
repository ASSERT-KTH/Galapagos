static void princ_object(snd_output_t *out, struct alisp_object * p)
{
	switch (alisp_get_type(p)) {
	case ALISP_OBJ_NIL:
		snd_output_printf(out, "nil");
		break;
	case ALISP_OBJ_T:
		snd_output_putc(out, 't');
		break;
	case ALISP_OBJ_IDENTIFIER:
		snd_output_printf(out, "%s", p->value.s);
		break;
	case ALISP_OBJ_STRING:
		princ_string(out, p->value.s);
		break;
	case ALISP_OBJ_INTEGER:
		snd_output_printf(out, "%ld", p->value.i);
		break;
	case ALISP_OBJ_FLOAT:
		snd_output_printf(out, "%f", p->value.f);
		break;
	case ALISP_OBJ_POINTER:
		snd_output_printf(out, "<%p>", p->value.ptr);
		break;
	case ALISP_OBJ_CONS:
		snd_output_putc(out, '(');
		princ_cons(out, p);
		snd_output_putc(out, ')');
	}
}