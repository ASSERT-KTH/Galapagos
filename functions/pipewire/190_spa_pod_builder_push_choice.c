spa_pod_builder_push_choice(struct spa_pod_builder *builder, struct spa_pod_frame *frame,
		uint32_t type, uint32_t flags)
{
	const struct spa_pod_choice p =
	    { {sizeof(struct spa_pod_choice_body) - sizeof(struct spa_pod), SPA_TYPE_Choice},
	    { type, flags, {0, 0}} };
	uint32_t offset = builder->state.offset;
	int res = spa_pod_builder_raw(builder, &p, sizeof(p) - sizeof(struct spa_pod));
	spa_pod_builder_push(builder, frame, &p.pod, offset);
	return res;
}