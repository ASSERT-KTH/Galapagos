static PyObject* pycsp_can_socketcan_init(PyObject *self, PyObject *args) {
    char* ifc;
    int bitrate = 1000000;
    int promisc = 0;
    if (!PyArg_ParseTuple(args, "s|ii", &ifc, &bitrate, &promisc)) {
        return NULL;
    }

    int res = csp_can_socketcan_open_and_add_interface(ifc, CSP_IF_CAN_DEFAULT_NAME, bitrate, promisc, NULL);
    if (res != CSP_ERR_NONE) {
        return PyErr_Error("csp_can_socketcan_open_and_add_interface()", res);
    }

    Py_RETURN_NONE;
}