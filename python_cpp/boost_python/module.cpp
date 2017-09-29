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

#include "library.h"
#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hello) {
    using namespace mylib;
    using namespace boost::python;

    // export simple function
    def("say_hello", say_hello, (arg("who")="John Doe"),
        "Display a simple greeting");

    // export class
    class_<Messenger>("Messenger", "A demo C++ object")
        .def("get_message", &Messenger::get_message,
            "Gets the message from the messenger")
        .def("set_message", &Messenger::set_message,
            "Puts a new message into the messenger");
}

