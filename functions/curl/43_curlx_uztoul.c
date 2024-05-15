unsigned long curlx_uztoul(size_t uznum)
{
#ifdef __INTEL_COMPILER
# pragma warning(push)
# pragma warning(disable:810) /* conversion may lose significant bits */
#endif

#if ULONG_MAX < SIZE_T_MAX
  DEBUGASSERT(uznum <= (size_t) CURL_MASK_ULONG);
#endif
  return (unsigned long)(uznum & (size_t) CURL_MASK_ULONG);

#ifdef __INTEL_COMPILER
# pragma warning(pop)
#endif
}