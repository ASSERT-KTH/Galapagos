1. Modifying the corresponding 'node' assigned to '[', instead fo printing 'test invocation':

emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "Brackets interpretation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  // remain unchanged...

  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " activation" : "");
}


2. Changing the PACKAGE_URL prefix from the last printf statement:

emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  // remain unchanged...

  char const *url_program = STREQ (program, "[") ? "test" : program;
  printf (_("Full documentation <%s/docs/%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}


3. Adding more tools' details on individual basis in the infomap[] array:

emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call programs and utilities" },
    { "sha224sum", "SHA-224 cryptographic hash." },
    { "sha256sum", "SHA-256 cryptographic hash." },
    { "sha384sum", "SHA-384 cryptographic hash." },
    { "sha512sum", "SHA-512 cryptographic hash." },
    { nullptr, nullptr }
  };

  // remain unchanged...

  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}


4. Adding clarification in the output of unspecified programs:

emit_ancillary_info (char const *program)
{
  struct infomap { char const *program; char const *node; } const infomap[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  // remain unchanged...

  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, url_program);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          node == program ? " "
		  : node , node == program ? "unknown, please refer to this<" PACKAGE_NAME ">'s specific invocation" : "");
}
