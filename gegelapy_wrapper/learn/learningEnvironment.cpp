#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <learn/learningEnvironment.h>
#include <boost/bind/bind.hpp>

#include <iterator>

namespace bp = boost::python;
using namespace Learn;
using namespace boost::placeholders;

// Wrapper for the LearningMode enum
void exposeLearningModeEnum() {
    bp::enum_<LearningMode>("LearningMode")
        .value("TRAINING", LearningMode::TRAINING)
        .value("VALIDATION", LearningMode::VALIDATION)
        .value("TESTING", LearningMode::TESTING);
}

// Wrapper for the LearningEnvironment class
class LearningEnvironmentWrapper : public LearningEnvironment, public bp::wrapper<LearningEnvironment> {
public:
    LearningEnvironmentWrapper(uint64_t nbAct)
        : LearningEnvironment(nbAct), bp::wrapper<LearningEnvironment>() {}

    LearningEnvironment* clone() const {
        if (bp::override func_clone = this->get_override("clone")) {
            return func_clone();
        }
        return LearningEnvironment::clone();
    }

    LearningEnvironment* default_clone() const {
        return LearningEnvironment::clone();
    }

    bool isCopyable() const {
        if (bp::override func_isCopyable = this->get_override("isCopyable")) {
            return func_isCopyable();
        }
        return LearningEnvironment::isCopyable();
    }

    bool default_isCopyable() const {
        return LearningEnvironment::isCopyable();
    }

    void doAction(uint64_t actionID) {
        if (bp::override func_doAction = this->get_override("doAction")) {
            func_doAction(actionID);
        } else {
            LearningEnvironment::doAction(actionID);
        }
    }

    void default_doAction(uint64_t actionID) {
        LearningEnvironment::doAction(actionID);
    }

    void reset(size_t seed = 0, LearningMode mode = LearningMode::TRAINING) {
        if (bp::override func_reset = this->get_override("reset")) {
            func_reset(seed, mode);
        } else {
            LearningEnvironment::reset(seed, mode);
        }
    }

    void default_reset(size_t seed = 0, LearningMode mode = LearningMode::TRAINING) {
        LearningEnvironment::reset(seed, mode);
    }

    std::vector<std::reference_wrapper<const Data::DataHandler>> getDataSources() {
        if (bp::override func_getDataSources = this->get_override("getDataSources")) {
            return func_getDataSources();
        }
        return LearningEnvironment::getDataSources();
    }

    std::vector<std::reference_wrapper<const Data::DataHandler>> default_getDataSources() {
        return LearningEnvironment::getDataSources();
    }

    double getScore() const {
        if (bp::override func_getScore = this->get_override("getScore")) {
            return func_getScore();
        }
        return LearningEnvironment::getScore();
    }

    double default_getScore() const {
        return LearningEnvironment::getScore();
    }

    bool isTerminal() const {
        if (bp::override func_isTerminal = this->get_override("isTerminal")) {
            return func_isTerminal();
        }
        return LearningEnvironment::isTerminal();
    }

    bool default_isTerminal() const {
        return LearningEnvironment::isTerminal();
    }

    private:
    LearningEnvironmentWrapper(const LearningEnvironmentWrapper&);
    LearningEnvironmentWrapper& operator=(const LearningEnvironmentWrapper&);
};

BOOST_PYTHON_MODULE(LearningEnvironment) {
    // Expose the LearningMode enum
    exposeLearningModeEnum();

    // Expose the LearningEnvironment class
    bp::class_<LearningEnvironmentWrapper, boost::noncopyable>("LearningEnvironment", bp::init<uint64_t>())
        .def("clone", &LearningEnvironment::clone, &LearningEnvironmentWrapper::default_clone, bp::return_value_policy<bp::reference_existing_object>())
        .def("isCopyable", &LearningEnvironment::isCopyable, &LearningEnvironmentWrapper::default_isCopyable)
        .def("doAction", &LearningEnvironment::doAction, &LearningEnvironmentWrapper::default_doAction)
        .def("reset", &LearningEnvironment::reset, &LearningEnvironmentWrapper::default_reset,
             (bp::arg("seed") = 0, bp::arg("mode") = LearningMode::TRAINING))
        .def("getDataSources", &LearningEnvironment::getDataSources, &LearningEnvironmentWrapper::default_getDataSources)
        .def("getScore", &LearningEnvironment::getScore, &LearningEnvironmentWrapper::default_getScore)
        .def("isTerminal", &LearningEnvironment::isTerminal, &LearningEnvironmentWrapper::default_isTerminal)
        ;
}
