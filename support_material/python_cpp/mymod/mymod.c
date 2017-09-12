#include <Python.h>

/***************************
 * Functions
 ***************************/
static PyObject *
mymod_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    
    sts = system(command);
    
    return PyLong_FromLong(sts);
}


/***************************
 * Method table
 ***************************/
static PyMethodDef mymod_methods[] = {
    {"system",  mymod_system, METH_VARARGS, "Execute a shell command."},
    {NULL, NULL, 0, NULL}        /* sentinel */
};


/***************************
 * Module exported symbols
 ***************************/
static struct PyModuleDef mymod_module = {
    PyModuleDef_HEAD_INIT,
    "mymod",   /* name of module */
    NULL,      /* module documentation */
    -1,        /* size of per-interpreter state of the module,
                  or -1 if the module keeps state in global variables. */
    mymod_methods
};


/***************************
 * Module creation function
 ***************************/
PyMODINIT_FUNC
PyInit_mymod(void)
{
    return PyModule_Create(&mymod_module);
}
