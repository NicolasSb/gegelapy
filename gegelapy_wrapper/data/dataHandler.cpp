#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include <data/dataHandler.h>

namespace bp = boost::python;

namespace Data {

    class DataHandler
    {
        // ... class implementation ...
    };

}

BOOST_PYTHON_MODULE(data_handler)
{
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
        .def("clone", bp::pure_virtual(&Data::DataHandler::clone))
        ;

    // Register the std::vector<size_t> indexing suite
    bp::class_<std::vector<size_t>>("AddressVector")
        .def(bp::vector_indexing_suite<std::vector<size_t>>());
}
