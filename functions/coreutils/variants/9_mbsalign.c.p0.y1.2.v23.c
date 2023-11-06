Here is the alternative implementation,


size_t mbsalign (char const *src, char *dst, size_t size, size_t *width, mbs_align_t align_type, int flags) 
{ 
  /* Convert to wide characters and then convert it back to multibyte sequence to avoid corrupting multibyte sequence */
  size_t len = (MB_CUR_MAX == 1 || (flags & MBA_UNIBYTE_ONLY)) ? strlen(src) : wcswidth(src, MB_CUR_MAX);
  size_t copy_bytes = MIN(len, *width); 
  
  switch(align_type) { 
    case MBS_ALIGN_LEFT: 
      memset(dst + copy_bytes, ' ', *width - copy_bytes); 
      break;
    case MBS_ALIGN_CENTER: {
      size_t pad = *width > len ? (*width - len) / 2 : 0; 
      memset(dst, ' ', pad); 
      memset(dst + pad + copy_bytes, ' ', *width - len - pad);
      dst += pad;
      break;}   
    case MBS_ALIGN_RIGHT: 
      memset(dst, ' ', *width - copy_bytes); 
        dst += *width - len; 
      break; }   

  if (!(flags & MBA_NO_EXTEND_TO_WIDTH)) { size *= *width / len;}
  *width = len; 
  
  return MIN(size - 1, strlen(strncpy(dst, src, MIN(copy_bytes, size - 1)))) + MAX(*width, len);
  
}
