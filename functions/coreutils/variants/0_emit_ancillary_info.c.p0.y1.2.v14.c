void emit_ancillary_info (char const *input)
{
  const struct { const char *exe; const char *description; } data[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { NULL, NULL }
  };

  const char *description = input;
  const struct *info = data;

  while (info->exe && strcmp(input, info->exe) != 0)
    info++;

  if (info->description)
    description = info->description;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  char const *messages = setlocale (LC_MESSAGES, NULL);
  
  if (messages && strncasecmp(messages, "en_")) {
    fputs (_("Report any translation bugs to "
             "<https://translationproject.org/team/>\n"), stdout);
  }

  char const *actual_exe = strcmp (input, "[") == 0 ? "test" : input;
      
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, actual_exe);
      
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          description, description == input ? " invocation" : ""); 
}
