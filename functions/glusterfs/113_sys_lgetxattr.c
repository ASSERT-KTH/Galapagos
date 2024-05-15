sys_lgetxattr (const char *path, const char *name, void *value, size_t size)
{

#if defined(GF_LINUX_HOST_OS) || defined(__NetBSD__)
        return lgetxattr (path, name, value, size);
#endif

#ifdef GF_BSD_HOST_OS
        return extattr_get_link (path, EXTATTR_NAMESPACE_USER, name, value,
                                 size);
#endif

#ifdef GF_SOLARIS_HOST_OS
        return solaris_getxattr (path, name, value, size);
#endif

#ifdef GF_DARWIN_HOST_OS
         return getxattr (path, name, value, size, 0, XATTR_NOFOLLOW);
#endif

}