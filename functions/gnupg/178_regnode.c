static int regnode(regex_t *preg, int op)
{
	reg_grow(preg, 2);

	/* The OP followed by a next pointer */
	preg->program[preg->p++] = op;
	preg->program[preg->p++] = 0;

	/* Return the start of the node */
	return preg->p - 2;
}