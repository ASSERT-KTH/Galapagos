static int ctxTypeID_to_size(int ctxTypeID) {
    switch(ctxTypeID) {
    case 1:
        return LZ4_sizeofState();
    case 2:
        return LZ4_sizeofStateHC();
    default:
        return 0;
    }
}