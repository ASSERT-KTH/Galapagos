static int get_string(char **string, int id, input_t *input)
{
	int c = get_nonwhite(input), err;
	if (c < 0)
		return c;
	switch (c) {
	case '=':
	case ',':
	case ';':
	case '.':
	case '{':
	case '}':
	case '[':
	case ']':
	case '\\':
		return LOCAL_UNEXPECTED_CHAR;
	case '\'':
	case '"':
		err = get_delimstring(string, c, input);
		if (err < 0)
			return err;
		return 1;
	default:
		unget_char(c, input);
		err = get_freestring(string, id, input);
		if (err < 0)
			return err;
		return 0;
	}
}