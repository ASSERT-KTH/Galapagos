1. Transformation with early return

randombytes_buf(void * const buf, const size_t size)
{
    if (size == 0U) {
        return;
    }

    randombytes_init_if_needed();
    implementation->buf(buf, size);
}


2. Transformation without the condition for size

randombytes_buf(void * const buf, const size_t size)
{
    randombytes_init_if_needed();
    implementation->buf(buf, ((size > (size_t) 0U) ? size : (size_t) 0U));
}


3. Transformation using ternary operator within function call

randombytes_buf(void * const buf, const size_t size)
{
    randombytes_init_if_needed();
    (size > 0U) ? implementation->buf(buf, size) : EXIT_SUCCESS;
}


4. Transformation with nested condition

randombytes_buf(void * const buf, const size_t size)
{
    (size > (size_t) 0U) ? randombytes_init_if_needed() : EXIT_SUCCESS;
    implementation->buf(buf, size);
}


5. Transformation with logical AND to evaluate second expression only if first is valid

randombytes_buf(void * const buf, const size_t size)
{
    size && randombytes_init_if_needed();
    implementation->buf(buf, size);
}
