static inline int spa_pod_parser_push_struct(struct spa_pod_parser *parser,
		struct spa_pod_frame *frame)
{
	const struct spa_pod *pod = spa_pod_parser_current(parser);
	if (pod == NULL)
		return -EPIPE;
	if (!spa_pod_is_struct(pod))
		return -EINVAL;
	spa_pod_parser_push(parser, frame, pod, parser->state.offset);
	parser->state.offset += sizeof(struct spa_pod_struct);
	return 0;
}