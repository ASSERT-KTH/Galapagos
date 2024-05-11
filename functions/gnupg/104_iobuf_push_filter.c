iobuf_push_filter (iobuf_t a,
		   int (*f) (void *opaque, int control,
			     iobuf_t chain, byte * buf, size_t * len),
                   void *ov)
{
  return iobuf_push_filter2 (a, f, ov, 0);
}