__argp_fmtstream_putc (argp_fmtstream_t __fs, int __ch)
{
  if (__fs->p < __fs->end || __argp_fmtstream_ensure (__fs, 1))
    return *__fs->p++ = __ch;
  else
    return EOF;
}