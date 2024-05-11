spa_format_parse(const struct spa_pod *format, uint32_t *media_type, uint32_t *media_subtype)
{
	return spa_pod_parse_object(format,
		SPA_TYPE_OBJECT_Format, NULL,
		SPA_FORMAT_mediaType,    SPA_POD_Id(media_type),
		SPA_FORMAT_mediaSubtype, SPA_POD_Id(media_subtype));
}