int BIO_indent(BIO *bio, unsigned indent, unsigned max_indent) {
  if (indent > max_indent) {
    indent = max_indent;
  }

  while (indent--) {
    if (BIO_puts(bio, " ") != 1) {
      return 0;
    }
  }
  return 1;
}