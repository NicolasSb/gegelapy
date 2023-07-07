#include <boost/python.hpp>
#include "tpg/policyStats.h"

namespace bp = boost::python;

using namespace TPG;

BOOST_PYTHON_MODULE(_policyStats)
{
    // Expose the PolicyStats class
    bp::class_<PolicyStats>("PolicyStats")
        .def("clear", &PolicyStats::clear)
        .def("setEnvironment", &PolicyStats::setEnvironment)
        .def("analyzeLine", &PolicyStats::analyzeLine)
        .def("analyzeProgram", &PolicyStats::analyzeProgram)
        .def("analyzeTPGTeam", &PolicyStats::analyzeTPGTeam)
        .def("analyzeTPGAction", &PolicyStats::analyzeTPGAction)
        .def("analyzePolicy", &PolicyStats::analyzePolicy)
        .def(bp::self_ns::str(bp::self_ns::self));

    // Expose the PolicyStats::nbUsePerProgram map
    bp::class_<std::map<const Program::Program*, size_t>>("ProgramUseMap")
        .def("__getitem__", +[](const std::map<const Program::Program*, size_t>& map, const Program::Program* key) -> size_t {
            auto iter = map.find(key);
            if (iter != map.end()) {
                return iter->second;
            }
            else {
                PyErr_SetString(PyExc_KeyError, "Key not found in map");
                bp::throw_error_already_set();
                return 0;  // Return a default value here
            }
        }, bp::args("self", "key"))
        .def("__getitem__", +[](const std::map<const Program::Program*, size_t>& map, const Program::Program* key) -> size_t {
            auto iter = map.find(key);
            if (iter != map.end()) {
                return iter->second;
            }
            else {
                PyErr_SetString(PyExc_KeyError, "Key not found in map");
                bp::throw_error_already_set();
                return 0;  // Return a default value here
            }
        }, bp::args("self", "key"));

    // Expose the PolicyStats::nbUsePerTPGTeam map
    bp::class_<std::map<const TPGTeam*, size_t>>("TPGTeamUseMap")
        .def("__getitem__", +[](const std::map<const TPGTeam*, size_t>& map, const TPGTeam* key) -> size_t {
            auto iter = map.find(key);
            if (iter != map.end()) {
                return iter->second;
            }
            else {
                PyErr_SetString(PyExc_KeyError, "Key not found in map");
                bp::throw_error_already_set();
                return 0;  // Return a default value here
            }
        }, bp::args("self", "key"))
        .def("__getitem__", +[](const std::map<const TPGTeam*, size_t>& map, const TPGTeam* key) -> size_t {
            auto iter = map.find(key);
            if (iter != map.end()) {
                return iter->second;
            }
            else {
                PyErr_SetString(PyExc_KeyError, "Key not found in map");
                bp::throw_error_already_set();
                return 0;  // Return a default value here
            }
        }, bp::args("self", "key"));

    // Expose the PolicyStats::nbUsePerTPGAction map
    bp::class_<std::map<const TPGAction*, size_t>>("TPGActionUseMap")
        .def("__getitem__", +[](const std::map<const TPGAction*, size_t>& map, const TPGAction* key) -> size_t {
            auto iter = map.find(key);
            if (iter != map.end()) {
                return iter->second;
            }
            else {
                PyErr_SetString(PyExc_KeyError, "Key not found in map");
                bp::throw_error_already_set();
                return 0;  // Return a default value here
            }
        }, bp::args("self", "key"))
        .def("__getitem__", +[](const std::map<const TPGAction*, size_t>& map, const TPGAction* key) -> size_t {
            auto iter = map.find(key);
            if (iter != map.end()) {
                return iter->second;
            }
            else {
                PyErr_SetString(PyExc_KeyError, "Key not found in map");
                bp::throw_error_already_set();
                return 0;  // Return a default value here
            }
        }, bp::args("self", "key"));

    // Expose the PolicyStats::nbUsagePerInstruction map
    bp::class_<std::map<size_t, size_t>>("InstructionUsageMap")
        .def("__getitem__", +[](const std::map<size_t, size_t>& map, size_t key) -> size_t {
            auto iter = map.find(key);
            if (iter != map.end()) {
                return iter->second;
            }
            else {
                PyErr_SetString(PyExc_KeyError, "Key not found in map");
                bp::throw_error_already_set();
                return 0;  // Return a default value here
            }
        }, bp::args("self", "key"))
        .def("__getitem__", +[](const std::map<size_t, size_t>& map, size_t key) -> size_t {
            auto iter = map.find(key);
            if (iter != map.end()) {
                return iter->second;
            }
            else {
                PyErr_SetString(PyExc_KeyError, "Key not found in map");
                bp::throw_error_already_set();
                return 0;  // Return a default value here
            }
        }, bp::args("self", "key"));

    // Expose the PolicyStats::nbUsagePerDataLocation map
    bp::class_<std::map<std::pair<size_t, size_t>, size_t>>("DataLocationUsageMap")
        .def("__getitem__", +[](const std::map<std::pair<size_t, size_t>, size_t>& map, std::pair<size_t, size_t> key) -> size_t {
            auto iter = map.find(key);
            if (iter != map.end()) {
                return iter->second;
            }
            else {
                PyErr_SetString(PyExc_KeyError, "Key not found in map");
                bp::throw_error_already_set();
                return 0;  // Return a default value here
            }
        }, bp::args("self", "key"))
        .def("__getitem__", +[](const std::map<std::pair<size_t, size_t>, size_t>& map, std::pair<size_t, size_t> key) -> size_t {
            auto iter = map.find(key);
            if (iter != map.end()) {
                return iter->second;
            }
            else {
                PyErr_SetString(PyExc_KeyError, "Key not found in map");
                bp::throw_error_already_set();
                return 0;  // Return a default value here
            }
        }, bp::args("self", "key"));
}
