#include <boost/python.hpp>
#include "learn/parallelLearningAgent.h"

namespace bp = boost::python;

// Expose the LearningParameters structure to Python
void exposeLearningParameters()
{
    // Create the Python class for LearningParameters
    bp::class_<Learn::LearningParameters, bp::bases<Learn::LearningAgent>>("LearningParameters")
        .def_readwrite("mutation", &Learn::LearningParameters::mutation)
        .def_readwrite("archiveSize", &Learn::LearningParameters::archiveSize)
        .def_readwrite("archivingProbability", &Learn::LearningParameters::archivingProbability)
        .def_readwrite("nbIterationsPerPolicyEvaluation", &Learn::LearningParameters::nbIterationsPerPolicyEvaluation)
        .def_readwrite("maxNbActionsPerEval", &Learn::LearningParameters::maxNbActionsPerEval)
        .def_readwrite("ratioDeletedRoots", &Learn::LearningParameters::ratioDeletedRoots)
        .def_readwrite("nbGenerations", &Learn::LearningParameters::nbGenerations)
        .def_readwrite("maxNbEvaluationPerPolicy", &Learn::LearningParameters::maxNbEvaluationPerPolicy)
        .def_readwrite("nbIterationsPerJob", &Learn::LearningParameters::nbIterationsPerJob)
        .def_readwrite("nbRegisters", &Learn::LearningParameters::nbRegisters)
        .def_readwrite("nbProgramConstant", &Learn::LearningParameters::nbProgramConstant)
        .def_readwrite("nbThreads", &Learn::LearningParameters::nbThreads)
        .def_readwrite("doValidation", &Learn::LearningParameters::doValidation);
}

BOOST_PYTHON_MODULE(parallelLearningAgent)
{
    // Expose the LearningParameters structure
    exposeLearningParameters();
}
