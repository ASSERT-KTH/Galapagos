is_open (int fd)
{
# if defined _WIN32 && ! defined __CYGWIN__
  /* On native Windows: The initial state of unassigned standard file
     descriptors is that they are open but point to an INVALID_HANDLE_VALUE.
     There is no fcntl, and the gnulib replacement fcntl does not support
     F_GETFL.  */
  return (HANDLE) _get_osfhandle (fd) != INVALID_HANDLE_VALUE;
# else
#  ifndef F_GETFL
#   error Please port fcntl to your platform
#  endif
  return 0 <= fcntl (fd, F_GETFL);
# endif
}