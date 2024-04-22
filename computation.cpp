#include "pybind11/pybind11.h"
#include <pybind11/stl.h>
#include "manupulator.h"

namespace py = pybind11;

PYBIND11_MODULE(brain, dark)
{
    dark.doc() = "documented by DARKLORD";

    dark.def("moves", &movegen);
    dark.def("hint", &aiMove);
    dark.def("play", &aiPlay);

    py::class_<piece>(dark, "set")
        .def(py::init<>())
        .def(py::init<int>())
        .def("getval", &piece::sndval);
    py::class_<moves>(dark, "arrayclass")
        .def(py::init<>())
        .def("getmove", [](const moves &ref)
             { return ref.posmoves; })
        .def("getpla", [](const moves &ref)
             { return ref.player; });
}
