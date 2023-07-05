#include <boost/python.hpp>
#include <learn/learningAgent.h>
#include <log/laPolicyStatsLogger.h>

namespace bp = boost::python;

namespace Log
{

    BOOST_PYTHON_MODULE(laPolicyStatsLogger)
    {
        // Expose the LAPolicyStatsLogger class to Python
        bp::class_<LAPolicyStatsLogger>("LAPolicyStatsLogger", bp::init<Learn::LearningAgent&, std::ostream&>())
            .def("logNewGeneration", &LAPolicyStatsLogger::logNewGeneration)
            .def("logHeader", &LAPolicyStatsLogger::logHeader)
            .def("logAfterPopulateTPG", &LAPolicyStatsLogger::logAfterPopulateTPG)
            .def("logAfterDecimate", &LAPolicyStatsLogger::logAfterDecimate)
            .def("logAfterValidate", &LAPolicyStatsLogger::logAfterValidate)
            .def("logEndOfTraining", &LAPolicyStatsLogger::logEndOfTraining)
            .def("logAfterEvaluate", &LAPolicyStatsLogger::logAfterEvaluate);
    }
}