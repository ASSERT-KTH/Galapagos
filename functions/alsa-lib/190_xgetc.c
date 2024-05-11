static int xgetc(struct alisp_instance *instance)
{
	instance->charno++;
	if (instance->lex_bufp > instance->lex_buf)
		return *--(instance->lex_bufp);
	return snd_input_getc(instance->in);
}