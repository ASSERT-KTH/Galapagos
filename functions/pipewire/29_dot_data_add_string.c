static void dot_data_add_string (struct dot_data * dd, const char *value)
{
	int size;
	dot_data_ensure_max_size (dd, strlen (value));
	size = snprintf (dd->data + dd->size, dd->max_size - dd->size, "%s", value);
	dd->size += size;
}