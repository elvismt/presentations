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
    using namespace boost::python;
    
    // export simple function
    def("hello", hello);
    
    // export class
    class_<World>("World")
        .def("get_message", &World::get_message)
        .def("set_message", &World::set_message);
}
