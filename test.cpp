#include<pybind11/pybind11.h>

int mult(int a,int b){
    return a*b*2;
}

PYBIND11_MODULE(module_name,handle){
    handle.doc("documented by DARKLORD");
    handle.def("darkmult",&mult);
}