char *pa_alsa_mixer_id_to_string(char *dst, size_t dst_len, pa_alsa_mixer_id *id) {
    if (id->index > 0) {
        snprintf(dst, dst_len, "'%s',%d", id->name, id->index);
    } else {
        snprintf(dst, dst_len, "'%s'", id->name);
    }
    return dst;
}