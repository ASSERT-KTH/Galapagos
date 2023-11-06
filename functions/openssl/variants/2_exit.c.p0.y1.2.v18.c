void exit(int status) {
    void (*realexit)(int) = NULL;
    struct timeval tv = {0, 100000};

    realexit = (void (*)(int)) dlsym(RTLD_NEXT, "exit");
    int res = select(0, NULL, NULL, NULL, &tv);
    
    if (realexit != NULL) {
        realexit(status);
    }
}