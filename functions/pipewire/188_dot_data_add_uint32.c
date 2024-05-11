static void dot_data_add_uint32 (struct dot_data * dd, uint32_t value)
{
	int size;
	dot_data_ensure_max_size (dd, 16);
	size = snprintf (dd->data + dd->size, dd->max_size - dd->size, "%u", value);
	dd->size += size;
}