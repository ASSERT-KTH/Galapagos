static PyObject* pycsp_buffer_free(PyObject *self, PyObject *args) {
    PyObject* packet_capsule;
    if (!PyArg_ParseTuple(args, "O", &packet_capsule)) {
        return NULL; // TypeError is thrown
    }

    csp_packet_t * packet = get_obj_as_packet(packet_capsule, true);
    if (packet) {
        csp_buffer_free(packet);
    }
    PyCapsule_SetPointer(packet_capsule, &CSP_POINTER_HAS_BEEN_FREED);
    Py_RETURN_NONE;
}