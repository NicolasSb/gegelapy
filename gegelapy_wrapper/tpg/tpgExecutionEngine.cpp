#include <boost/python.hpp>
#include <boost/python/object.hpp>
#include <boost/python/make_function.hpp>
#include "tpg/tpgExecutionEngine.h"

namespace bp = boost::python;
using namespace TPG;

class TPGExecutionEngineWrapper : public TPGExecutionEngine, public bp::wrapper<TPGExecutionEngine> {
public:
    TPGExecutionEngineWrapper(const Environment& env, Archive* arch = nullptr)
        : TPGExecutionEngine(env, arch), bp::wrapper<TPGExecutionEngine>() {}

    void setArchive(Archive* newArchive) {
        if (bp::override func_setArchive = this->get_override("setArchive")) {
            func_setArchive(newArchive);
        } else {
            TPGExecutionEngine::setArchive(newArchive);
        }
    }

    void default_setArchive(Archive* newArchive) {
        TPGExecutionEngine::setArchive(newArchive);
    }

    double evaluateEdge(const TPGEdge& edge) {
        if (bp::override func_evaluateEdge = this->get_override("evaluateEdge")) {
            return func_evaluateEdge(edge);
        }
        return TPGExecutionEngine::evaluateEdge(edge);
    }

    double default_evaluateEdge(const TPGEdge& edge) {
        return TPGExecutionEngine::evaluateEdge(edge);
    }

    const TPG::TPGEdge& evaluateTeamWrapper(const TPGTeam& team) {
        if (bp::override func_evaluateTeam = this->get_override("evaluateTeam")) {
            bp::object result = func_evaluateTeam(team);
            return bp::extract<const TPG::TPGEdge&>(result);
        }
        return TPGExecutionEngine::evaluateTeam(team);
    }

    const TPG::TPGEdge& default_evaluateTeamWrapper(const TPGTeam& team) {
        return TPGExecutionEngine::evaluateTeam(team);
    }

    const std::vector<const TPGVertex*> executeFromRoot(const TPGVertex& root) {
        if (bp::override func_executeFromRoot = this->get_override("executeFromRoot")) {
            return func_executeFromRoot(root);
        }
        return TPGExecutionEngine::executeFromRoot(root);
    }

    const std::vector<const TPGVertex*> default_executeFromRoot(const TPGVertex& root) {
        return TPGExecutionEngine::executeFromRoot(root);
    }
};

BOOST_PYTHON_MODULE(tpgExecutionEngine) {
    bp::class_<TPGExecutionEngineWrapper, boost::noncopyable>("TPGExecutionEngine", bp::init<const Environment&, Archive*>())
        .def("setArchive", &TPGExecutionEngineWrapper::setArchive, &TPGExecutionEngineWrapper::default_setArchive)
        .def("evaluateEdge", &TPGExecutionEngineWrapper::evaluateEdge, &TPGExecutionEngineWrapper::default_evaluateEdge)
        .def("evaluateTeam", &TPGExecutionEngineWrapper::evaluateTeamWrapper,
            &TPGExecutionEngineWrapper::default_evaluateTeamWrapper,
            bp::return_value_policy<bp::reference_existing_object>())
        .def("executeFromRoot", &TPGExecutionEngineWrapper::executeFromRoot, &TPGExecutionEngineWrapper::default_executeFromRoot)
        ;
}
