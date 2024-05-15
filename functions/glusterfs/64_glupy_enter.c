glupy_enter (void)
{
        if (!pthread_getspecific(gil_init_key)) {
                PyEval_ReleaseLock();
                (void)pthread_setspecific(gil_init_key,(void *)1);
        }

        return PyGILState_Ensure();
}