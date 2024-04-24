BIO *BIO_push(BIO *bio, BIO *appended_bio) {
  BIO *last_bio;

  if (bio == NULL) {
    return bio;
  }

  last_bio = bio;
  while (last_bio->next_bio != NULL) {
    last_bio = last_bio->next_bio;
  }

  last_bio->next_bio = appended_bio;
  return bio;
}