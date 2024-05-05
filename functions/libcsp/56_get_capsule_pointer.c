static void * get_capsule_pointer(PyObject* capsule, const char* expected_type, bool allow_null) {
    const char* capsule_name = PyCapsule_GetName(capsule);
    if (strcmp(capsule_name, expected_type) != 0) {
        PyErr_Format(PyExc_TypeError,
                     "capsule contains unexpected type, expected=%s, got=%s",
                     expected_type, capsule_name); // TypeError is thrown
        return NULL;
    }
    void * ptr = PyCapsule_GetPointer(capsule, expected_type);
    if (ptr == &CSP_POINTER_HAS_BEEN_FREED) {
        ptr = NULL;
    }
    if ((ptr == NULL) && !allow_null) {
        PyErr_Format(PyExc_TypeError,
                     "capsule: type=%s - already freed",
                     expected_type); // TypeError is thrown
        return NULL;
    }
    return ptr;
}