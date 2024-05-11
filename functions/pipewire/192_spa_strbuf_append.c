static inline int spa_strbuf_append(struct spa_strbuf *buf, const char *fmt, ...)
{
	size_t remain = buf->maxsize - buf->pos;
	ssize_t written;
	va_list args;
	va_start(args, fmt);
	written = vsnprintf(&buf->buffer[buf->pos], remain, fmt, args);
	va_end(args);
	if (written > 0)
		buf->pos += SPA_MIN(remain, (size_t)written);
	return written;
}