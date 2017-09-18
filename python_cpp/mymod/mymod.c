/*
 * Copyright (C) 2017  Elvis M. Teixeira
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Python.h>

/*==----------------------------------------------------------==
 Functions
==----------------------------------------------------------==*/
static PyObject *
mymod_system(PyObject *self, PyObject *args)
{
    const char *command = NULL;
    int result = 0;

    if (PyArg_ParseTuple(args, "s", &command) == 0) {
        PyErr_SetString(
            PyExc_TypeError,
            "Expected a single string argument");
        return NULL;
    }
    
    
    if ((result = system(command)) == -1) {
        PyErr_SetString(
            PyExc_ChildProcessError,
            "Could not execute external command");
        return NULL;
    }
    
    return PyLong_FromLong(result);
}


/*==----------------------------------------------------------==
 Method table
==----------------------------------------------------------==*/
static PyMethodDef mymod_methods[] = {
    {
        /* Members:
         *   - name of the method
         *   - pointer to the function
         *   - calling convention
         *   - docstring
         */
        "system",
        mymod_system,
        METH_VARARGS,
        "Execute a shell command"
    },
    
    /* sentinel that marks the end of the array */
    {NULL, NULL, 0, NULL}
};


/*==----------------------------------------------------------==
 Module exported symbols
==----------------------------------------------------------==*/
static struct PyModuleDef mymod_module = {
    /* Members:
     *   - a misterious header
     *   - name of module
     *   - module doc string
     *   - size of per-interpreter state of the module
     *   - method defs
     */
    PyModuleDef_HEAD_INIT,
    "mymod",
    "Demo module for native extensions",
    -1,
    mymod_methods   
};


/*==----------------------------------------------------------==
 Module creation function
==----------------------------------------------------------==*/
PyMODINIT_FUNC
PyInit_mymod(void)
{
    return PyModule_Create(&mymod_module);
}

