#include <boost/python.hpp>
#include "file/tpgGraphDotExporter.h"

namespace bp = boost::python;

namespace File
{

    BOOST_PYTHON_MODULE(tpgGraphDotExporter)
    {
        // Expose the TPGGraphDotExporter class to Python
        bp::class_<TPGGraphDotExporter>("TPGGraphDotExporter", bp::init<const char*, const TPG::TPGGraph&>())
            .def("setNewFilePath", &TPGGraphDotExporter::setNewFilePath)
            .def("print", &TPGGraphDotExporter::print)
            .def("printSubGraph", &TPGGraphDotExporter::printSubGraph);
    }
}