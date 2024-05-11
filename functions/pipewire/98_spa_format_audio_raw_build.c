spa_format_audio_raw_build(struct spa_pod_builder *builder, uint32_t id,
			   const struct spa_audio_info_raw *info)
{
	struct spa_pod_frame f;
	spa_pod_builder_push_object(builder, &f, SPA_TYPE_OBJECT_Format, id);
	spa_pod_builder_add(builder,
			SPA_FORMAT_mediaType,		SPA_POD_Id(SPA_MEDIA_TYPE_audio),
			SPA_FORMAT_mediaSubtype,	SPA_POD_Id(SPA_MEDIA_SUBTYPE_raw),
			0);
	if (info->format != SPA_AUDIO_FORMAT_UNKNOWN)
		spa_pod_builder_add(builder,
			SPA_FORMAT_AUDIO_format,	SPA_POD_Id(info->format), 0);
	if (info->rate != 0)
		spa_pod_builder_add(builder,
			SPA_FORMAT_AUDIO_rate,		SPA_POD_Int(info->rate), 0);
	if (info->channels != 0) {
		spa_pod_builder_add(builder,
			SPA_FORMAT_AUDIO_channels,	SPA_POD_Int(info->channels), 0);
		if (!SPA_FLAG_IS_SET(info->flags, SPA_AUDIO_FLAG_UNPOSITIONED)) {
			spa_pod_builder_add(builder, SPA_FORMAT_AUDIO_position,
				SPA_POD_Array(sizeof(uint32_t), SPA_TYPE_Id,
					info->channels, info->position), 0);
		}
	}
	return (struct spa_pod*)spa_pod_builder_pop(builder, &f);
}