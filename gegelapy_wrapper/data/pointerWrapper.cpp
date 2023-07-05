#include <boost/python.hpp>
#include <data/pointerWrapper.h>
#include <data/primitiveTypeArray.h>

namespace bp = boost::python;

namespace Data {

    // Declare the PointerWrapper template class
    template <class T>
    class PointerWrapper;

} // namespace Data
BOOST_PYTHON_MODULE(rng)
{
    // Register the PointerWrapper template class
    bp::class_<Data::PointerWrapper<int>>("PointerWrapperInt", bp::init<int*>())
        .def("setPointer", &Data::PointerWrapper<int>::setPointer)
        .def("getDataAt", &Data::PointerWrapper<int>::getDataAt)
        .def("getAddressesAccessed", &Data::PointerWrapper<int>::getAddressesAccessed);
        // Add other member functions and properties as needed
}