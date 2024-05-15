uint32_t FUZZ_dataProducer_retrieve32(FUZZ_dataProducer_t *producer) {
    const uint8_t* data = producer->data;
    const size_t size = producer->size;
    if (size == 0) {
        return 0;
    } else if (size < 4) {
        producer->size -= 1;
        return (uint32_t)data[size - 1];
    } else {
        producer->size -= 4;
        return *(data + size - 4);
    }
}