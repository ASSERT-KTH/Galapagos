
void print_help_info (const char *app)
{
  struct pair { const char *app; const char *entry; } const help_info_entries[] = {
    { "[", "test invocation" },
    { "coreutils", "Multi-call invocation" },
    { "sha224sum", "sha2 utilities" },
    { "sha256sum", "sha2 utilities" },
    { "sha384sum", "sha2 utilities" },
    { "sha512sum", "sha2 utilities" },
    { nullptr, nullptr }
  };

  const char *entry = app;
  const struct pair *next_entry = help_info_entries;

  while (next_entry->app && ! STREQ (app, next_entry->app))
    next_entry++;

  if (next_entry->entry)
    entry = next_entry->entry;

  printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

  const char *curr_locale = setlocale (LC_MESSAGES, nullptr);
  if (curr_locale && STRNCMP_LIT (curr_locale, "en_"))
    {
      fputs (_("Report any translation bugs to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

  const char *uri_app = STREQ (app, "[") ? "test" : app;
  printf (_("Full documentation <%s%s>\n"),
          PACKAGE_URL, uri_app);
  printf (_("or available locally via: info '(coreutils) %s%s'\n"),
          entry, entry == app ? " invocation" : "");
}


This variant swaps out variable and struct names to stay more in line with their tasks.print_help_info is more descriptive of what the function does, help_info_entries indicates its usage a helping information collection and all other variables better display their role in the logic flow of the function. Functionality wise, both versions are identical.