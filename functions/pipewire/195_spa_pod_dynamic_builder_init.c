static inline void spa_pod_dynamic_builder_init(struct spa_pod_dynamic_builder *builder,
		void *data, uint32_t size, uint32_t extend)
{
	static const struct spa_pod_builder_callbacks spa_pod_dynamic_builder_callbacks = {
		.version = SPA_VERSION_POD_BUILDER_CALLBACKS,
		.overflow = spa_pod_dynamic_builder_overflow
	};
	builder->b = SPA_POD_BUILDER_INIT(data, size);
	spa_pod_builder_set_callbacks(&builder->b, &spa_pod_dynamic_builder_callbacks, builder);
	builder->extend = extend;
	builder->data = data;
}