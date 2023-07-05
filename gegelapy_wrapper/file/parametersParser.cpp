#include <boost/python.hpp>
#include "file/parametersParser.h"

namespace bp = boost::python;

namespace File::ParametersParser
{
    BOOST_PYTHON_MODULE(parametersParser)
    {
        // Expose the loadParametersFromJson function
        bp::def("loadParametersFromJson", loadParametersFromJson);

        // Expose the writeParametersToJson function
        bp::def("writeParametersToJson", writeParametersToJson);
    }
}
