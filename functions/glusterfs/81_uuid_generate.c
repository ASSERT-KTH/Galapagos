void uuid_generate(uuid_t out)
{
	if (get_random_fd() >= 0)
		uuid_generate_random(out);
	else
		uuid_generate_time(out);
}