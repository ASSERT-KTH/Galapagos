profile_release(profile_t profile)
{
    prf_file_t      p, next;

    if (!profile || profile->magic != PROF_MAGIC_PROFILE)
        return;

    if (profile->vt) {
        /* Flush the profile and then delegate to profile_abandon. */
        if (profile->vt->flush)
            profile->vt->flush(profile->cbdata);
        profile_abandon(profile);
        return;
    } else {
        for (p = profile->first_file; p; p = next) {
            next = p->next;
            profile_close_file(p);
        }
    }
    profile->magic = 0;
    free(profile);
}