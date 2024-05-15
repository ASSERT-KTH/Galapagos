profile_get_string(profile_t profile, const char *name, const char *subname,
                   const char *subsubname, const char *def_val,
                   char **ret_string)
{
    char            *value;
    errcode_t       retval;
    const char      *names[4];

    if (profile) {
        names[0] = name;
        names[1] = subname;
        names[2] = subsubname;
        names[3] = 0;
        retval = profile_get_value(profile, names, &value);
        if (retval == 0) {
            *ret_string = value;
            return 0;
        } else if (retval != PROF_NO_SECTION && retval != PROF_NO_RELATION)
            return retval;
    }

    if (def_val) {
        *ret_string = strdup(def_val);
        if (*ret_string == NULL)
            return ENOMEM;
    } else
        *ret_string = NULL;
    return 0;
}