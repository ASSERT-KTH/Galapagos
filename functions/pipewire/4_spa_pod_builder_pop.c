static inline void *spa_pod_builder_pop(struct spa_pod_builder *builder, struct spa_pod_frame *frame)
{
	struct spa_pod *pod;

	if (SPA_FLAG_IS_SET(builder->state.flags, SPA_POD_BUILDER_FLAG_FIRST)) {
		const struct spa_pod p = { 0, SPA_TYPE_None };
		spa_pod_builder_raw(builder, &p, sizeof(p));
	}
	if ((pod = (struct spa_pod*)spa_pod_builder_frame(builder, frame)) != NULL)
		*pod = frame->pod;

	builder->state.frame = frame->parent;
	builder->state.flags = frame->flags;
	spa_pod_builder_pad(builder, builder->state.offset);
	return pod;
}