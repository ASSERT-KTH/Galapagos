linkat (int fd1, char const *file1, int fd2, char const *file2, int flag)
{
  if (flag & ~AT_SYMLINK_FOLLOW)
    {
      errno = EINVAL;
      return -1;
    }
  return at_func2 (fd1, file1, fd2, file2,
                   flag ? link_follow : link_immediate);
}