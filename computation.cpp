#include "pybind11/pybind11.h"
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include "brain.h"

namespace py = pybind11;

PYBIND11_MODULE(brain, dark)
{
    dark.doc() = "documented by DARKLORD";

    dark.def("moves", &movegen);
    dark.def("play", &aiMove);

    py::class_<piece>(dark, "set")
        .def(py::init<int,int>())
        .def("getval", &piece::sndval)
        .def("move", &piece::move)
        .def("value", [](const piece &reff)
             { return reff.value; })
        .def("detal", [](const piece &reff) -> std::pair<int, int>
             { return {reff.value, reff.side}; });

    py::class_<allmoves>(dark, "arrayclass")
        .def(py::init<>())
        .def("getmove", [](const allmoves &ref)
             { return ref.posmoves; })
        .def("getpla", [](const allmoves &ref)
             { return ref.player; });
}
