spa_pod_builder_push_object(struct spa_pod_builder *builder, struct spa_pod_frame *frame,
		uint32_t type, uint32_t id)
{
	const struct spa_pod_object p =
	    SPA_POD_INIT_Object(sizeof(struct spa_pod_object_body), type, id);
	uint32_t offset = builder->state.offset;
	int res = spa_pod_builder_raw(builder, &p, sizeof(p));
	spa_pod_builder_push(builder, frame, &p.pod, offset);
	return res;
}