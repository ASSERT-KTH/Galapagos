spa_pod_builder_push_struct(struct spa_pod_builder *builder, struct spa_pod_frame *frame)
{
	const struct spa_pod_struct p = SPA_POD_INIT_Struct(0);
	uint32_t offset = builder->state.offset;
	int res = spa_pod_builder_raw(builder, &p, sizeof(p));
	spa_pod_builder_push(builder, frame, &p.pod, offset);
	return res;
}