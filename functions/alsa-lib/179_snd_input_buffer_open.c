int snd_input_buffer_open(snd_input_t **inputp, const char *buf, ssize_t size)
{
	snd_input_t *input;
	snd_input_buffer_t *buffer;
	assert(inputp);
	buffer = calloc(1, sizeof(*buffer));
	if (!buffer)
		return -ENOMEM;
	input = calloc(1, sizeof(*input));
	if (!input) {
		free(buffer);
		return -ENOMEM;
	}
	if (size < 0)
		size = strlen(buf);
	buffer->buf = malloc((size_t)size + 1);
	if (!buffer->buf) {
		free(input);
		free(buffer);
		return -ENOMEM;
	}
	memcpy(buffer->buf, buf, (size_t) size);
	buffer->buf[size] = 0;
	buffer->ptr = buffer->buf;
	buffer->size = size;
	input->type = SND_INPUT_BUFFER;
	input->ops = &snd_input_buffer_ops;
	input->private_data = buffer;
	*inputp = input;
	return 0;
}