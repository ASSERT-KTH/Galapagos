_nm_utils_ascii_str_to_int64(const char *str, guint base, gint64 min, gint64 max, gint64 fallback)
{
    gint64      v;
    const char *s = NULL;

    str = nm_str_skip_leading_spaces(str);
    if (!str || !str[0]) {
        errno = EINVAL;
        return fallback;
    }

    errno = 0;
    v     = nm_g_ascii_strtoll(str, (char **) &s, base);

    if (errno != 0)
        return fallback;

    if (s[0] != '\0') {
        s = nm_str_skip_leading_spaces(s);
        if (s[0] != '\0') {
            errno = EINVAL;
            return fallback;
        }
    }
    if (v > max || v < min) {
        errno = ERANGE;
        return fallback;
    }

    return v;
}