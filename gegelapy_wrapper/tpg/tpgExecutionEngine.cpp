#include <boost/python.hpp>
#include "tpg/tpgExecutionEngine.h" // Assuming this is the header file containing the TPG namespace

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

    const TPGEdge& evaluateTeam(const TPGTeam& team) {
        if (bp::override func_evaluateTeam = this->get_override("evaluateTeam")) {
            return func_evaluateTeam(team);
        }
        return TPGExecutionEngine::evaluateTeam(team);
    }

    const TPGEdge& default_evaluateTeam(const TPGTeam& team) {
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
        .def("setArchive", &TPGExecutionEngine::setArchive, &TPGExecutionEngineWrapper::default_setArchive)
        .def("evaluateEdge", &TPGExecutionEngine::evaluateEdge, &TPGExecutionEngineWrapper::default_evaluateEdge)
        .def("evaluateTeam", &TPGExecutionEngine::evaluateTeam, &TPGExecutionEngineWrapper::default_evaluateTeam)
        .def("executeFromRoot", &TPGExecutionEngine::executeFromRoot, &TPGExecutionEngineWrapper::default_executeFromRoot)
        ;
}
