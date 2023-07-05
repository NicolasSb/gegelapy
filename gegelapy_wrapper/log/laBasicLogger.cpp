#include <boost/python.hpp>
#include "log/laBasicLogger.h"

namespace bp = boost::python;

namespace Log
    {

    BOOST_PYTHON_MODULE(laBasicLogger)
    {
        // Expose the LABasicLogger class to Python
        bp::class_<LABasicLogger, bp::bases<LALogger>>("LABasicLogger", bp::init<Learn::LearningAgent&, std::ostream&>())
            .def("logHeader", &LABasicLogger::logHeader)
            .def("logNewGeneration", &LABasicLogger::logNewGeneration)
            .def("logAfterPopulateTPG", &LABasicLogger::logAfterPopulateTPG)
            .def("logAfterEvaluate", &LABasicLogger::logAfterEvaluate)
            .def("logAfterDecimate", &LABasicLogger::logAfterDecimate)
            .def("logAfterValidate", &LABasicLogger::logAfterValidate)
            .def("logEndOfTraining", &LABasicLogger::logEndOfTraining);
    }
}