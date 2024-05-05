int csp_bytesize(char *buffer, int buffer_len, unsigned long int bytes) {
	char postfix;
	double size;

	if (bytes >= 1048576) {
		size = bytes/1048576.0;
		postfix = 'M';
	} else if (bytes >= 1024) {
		size = bytes/1024.0;
		postfix = 'K';
	} else {
		size = bytes;
		postfix = 'B';
 	}

	return snprintf(buffer, buffer_len, "%.1f%c", size, postfix);
}