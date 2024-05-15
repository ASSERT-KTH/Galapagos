static void LZ4IO_writeBuffer(BufferDesc bufDesc, FILE* out)
{
    size_t const size = bufDesc.size;
    if (fwrite(bufDesc.buf, 1, size, out) != size) {
        END_PROCESS(38, "Write error : cannot write compressed block");
    }
}