c32_apply_type_test (wint_t wc, c32_type_test_t property)
{
#if _GL_WCHAR_T_IS_UCS4
  return iswctype (wc, property);
#else
  return property (wc);
#endif
}