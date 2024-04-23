c32tob (wint_t wc)
{
#if HAVE_WORKING_MBRTOC32 && !_GL_WCHAR_T_IS_UCS4
  /* The char32_t encoding of a multibyte character may be different than its
     wchar_t encoding.  */
  if (wc != WEOF)
    {
      mbstate_t state;
      char buf[8];

      mbszero (&state);
      if (c32rtomb (buf, wc, &state) == 1)
        return (unsigned char) buf[0];
    }
  return EOF;
#elif _GL_SMALL_WCHAR_T
  /* In all known encodings, unibyte characters correspond only to
     characters in the BMP.  */
  if (wc != WEOF && (wchar_t) wc == wc)
    return wctob ((wchar_t) wc);
  else
    return EOF;
#else
# if GL_CHAR32_T_IS_UNICODE && GL_CHAR32_T_VS_WCHAR_T_NEEDS_CONVERSION
  if (wc != 0)
    {
      wc = unicode_to_locale_encoding (wc);
      if (wc == 0)
        return EOF;
    }
# endif
  return wctob (wc);
#endif
}