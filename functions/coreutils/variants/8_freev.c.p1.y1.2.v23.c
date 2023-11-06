Variant 1:

void freev(VALUE *v)
{
	if(v == NULL) return;
	switch(v->type) {
		case string:
			free(v->u.s);
			break; 
		default: 
			mpz_clear(v->u.i); 
	}
	free(v);
}


Variant 2:

void freev(VALUE *v)
{
	if (v != NULL)
	{
		if (v->type == string) free(v->u.s);
		if (v->type != string) mpz_clear(v->u.i);
		free(v);
	}
}

  
Variant 3:

void freev(VALUE *v)
{
	assert(v != NULL);
	if (v->type == string)
	{
		free(v->u.s);
		v->u.s = NULL;
	}
	else
	{
		mpz_clear(v->u.i);
	}
	free(v);
	v = NULL;
}
