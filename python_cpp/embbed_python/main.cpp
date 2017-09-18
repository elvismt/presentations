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

#include <iostream>
#include <fstream>
#include <string>

#include <Python.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "C++: You must provide a script name" << std::endl;
        return 8;
    }
    
    //
    // initialize a python interpreter instance
    //
    Py_Initialize();
    
    //
    // import it's main module and get it's dict
    //
    PyObject *main_module = PyImport_ImportModule("__main__");
    PyObject *main_module_dict = PyModule_GetDict(main_module);
    
    //
    // create a list, populate it and add it to the main modules dict
    // being in __main__.__dict__ means this list will be a global
    // variable in the script executed by the active interpreter
    //
    PyObject *pylist = PyList_New(2);
    PyDict_SetItemString(main_module_dict, "the_list", pylist);
    
    PyObject *pytwo = PyFloat_FromDouble(2.0);
    PyList_SetItem(pylist, 0, pytwo);
    
    PyObject *pythree = PyFloat_FromDouble(3.0);
    PyList_SetItem(pylist, 1, pythree);
    
    //
    // read the script from the source file
    //
    std::ifstream file_stream(argv[1]);
    std::string script_source;
    script_source.assign(std::istreambuf_iterator<char>{file_stream},
                          std::istreambuf_iterator<char>{});
    
    //
    // !!!Here is the meat!!! execute the script
    //
    PyRun_SimpleString(script_source.c_str());
    
    //
    // get the response string the script will create
    //
    PyObject *pyresponse = PyDict_GetItemString(main_module_dict, "response");
    std::cout << "C++: Python response is: "
              << PyUnicode_AsUTF8(pyresponse) << std::endl;
    
    //
    // Don't forget to dispose all variables at the end
    //
    Py_XDECREF(main_module);
    Py_XDECREF(main_module_dict);
    Py_XDECREF(pylist);
    Py_XDECREF(pytwo);
    Py_XDECREF(pythree);
    Py_XDECREF(pyresponse);
    
    //
    // Finalize the interpreter
    //
    Py_Finalize();
    return 0;
}

