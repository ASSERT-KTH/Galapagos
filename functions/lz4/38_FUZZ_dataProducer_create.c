FUZZ_dataProducer_t* FUZZ_dataProducer_create(const uint8_t* data, size_t size) {
  FUZZ_dataProducer_t* const producer = malloc(sizeof(FUZZ_dataProducer_t));

  FUZZ_ASSERT(producer != NULL);

  producer->data = data;
  producer->size = size;
  return producer;
}