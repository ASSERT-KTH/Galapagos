const char* LZ4IO_blockTypeID(LZ4F_blockSizeID_t sizeID, LZ4F_blockMode_t blockMode, char buffer[4])
{
    buffer[0] = 'B';
    assert(sizeID >= 4); assert(sizeID <= 7);
    buffer[1] = (char)(sizeID + '0');
    buffer[2] = (blockMode == LZ4F_blockIndependent) ? 'I' : 'D';
    buffer[3] = 0;
    return buffer;
}