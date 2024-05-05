static PyObject* pycsp_buffer_get(PyObject *self, PyObject *args) {
    size_t size;
    if (!PyArg_ParseTuple(args, "n", &size)) {
        return NULL; // TypeError is thrown
    }

    void* packet = csp_buffer_get(size);
    if (packet == NULL) {
        return PyErr_Error("csp_buffer_get() - no free buffers or data overrun", CSP_ERR_NOMEM);
    }

    return PyCapsule_New(packet, PACKET_CAPSULE, pycsp_free_csp_buffer);
}