spa_pod_filter(struct spa_pod_builder *b,
	       struct spa_pod **result,
	       const struct spa_pod *pod,
	       const struct spa_pod *filter)
{
	int res;
	struct spa_pod_builder_state state;

        spa_return_val_if_fail(pod != NULL, -EINVAL);
        spa_return_val_if_fail(b != NULL, -EINVAL);

	spa_pod_builder_get_state(b, &state);
	if (filter == NULL)
		res = spa_pod_builder_raw_padded(b, pod, SPA_POD_SIZE(pod));
	else
		res = spa_pod_filter_part(b, pod, SPA_POD_SIZE(pod), filter, SPA_POD_SIZE(filter));

	if (res < 0) {
		spa_pod_builder_reset(b, &state);
	} else if (result) {
		*result = (struct spa_pod*)spa_pod_builder_deref(b, state.offset);
		if (*result == NULL)
			res = -ENOSPC;
	}
	return res;
}