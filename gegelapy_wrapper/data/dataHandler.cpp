#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/bind/bind.hpp>


#include <data/dataHandler.h>
#include <data/untypedSharedPtr.h>
namespace bp = boost::python;

// Custom converter for UntypedSharedPtr

struct UntypedSharedPtrToPythonConverter
{
    static PyObject* convert(const Data::UntypedSharedPtr& ptr)
    {
        // Check if the pointer is null
        if (ptr.getSharedPointer<Data::DataHandler>() == nullptr)
        {
            Py_RETURN_NONE;
        }

        // Create a new shared_ptr object and transfer ownership to Python
        std::shared_ptr<Data::DataHandler> sharedPtr = ptr.getSharedPointer<Data::DataHandler>();
        return bp::incref(bp::object(sharedPtr).ptr());
    }
};

// Define a helper function to register the converter
void register_converter()
{
    bp::to_python_converter<Data::UntypedSharedPtr, UntypedSharedPtrToPythonConverter>();
}

BOOST_PYTHON_MODULE(DataHandler)
{
    register_converter();

    // Register the custom converter for UntypedSharedPtr
    bp::to_python_converter<Data::UntypedSharedPtr, UntypedSharedPtrToPythonConverter>();

    bp::class_<Data::DataHandler, boost::shared_ptr<Data::DataHandler>, boost::noncopyable>("DataHandler", bp::no_init)
        .def("getId", &Data::DataHandler::getId)
        .def("getHash", &Data::DataHandler::getHash)
        .def("canHandle", &Data::DataHandler::canHandle)
        .def("getAddressSpace", &Data::DataHandler::getAddressSpace)
        .def("getLargestAddressSpace", &Data::DataHandler::getLargestAddressSpace)
        .def("resetData", &Data::DataHandler::resetData)
        .def("getDataAt", &Data::DataHandler::getDataAt)
        .def("getAddressesAccessed", &Data::DataHandler::getAddressesAccessed)
        .def("scaleLocation", &Data::DataHandler::scaleLocation)
        .def("clone", bp::pure_virtual(&Data::DataHandler::clone), bp::return_value_policy<bp::reference_existing_object>()); // Specify return value policy

    // Expose the getSharedPointer function
    bp::def("getSharedPointer", &Data::UntypedSharedPtr::getSharedPointer<Data::DataHandler>);
    
    // Register the std::vector<size_t> indexing suite
    bp::class_<std::vector<size_t>>("AddressVector")
        .def(bp::vector_indexing_suite<std::vector<size_t>>());
}
