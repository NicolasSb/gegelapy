#include <boost/python.hpp>
#include <mutex>
#include <queue>
#include <thread>

#include "instructions/set.h"
#include "tpg/tpgExecutionEngine.h"

#include "learn/evaluationResult.h"
#include "learn/job.h"
#include "learn/learningAgent.h"
#include "learn/learningEnvironment.h"
#include "learn/learningParameters.h"

namespace Learn {
    class ParallelLearningAgent : public LearningAgent {
      protected:
        void evaluateAllRootsInParallel(
            uint64_t generationNumber, LearningMode mode,
            std::multimap<std::shared_ptr<EvaluationResult>,
                          const TPG::TPGVertex*>& results);

        void evaluateAllRootsInParallelExecute(
            uint64_t generationNumber, LearningMode mode,
            std::map<uint64_t, std::pair<std::shared_ptr<EvaluationResult>,
                                         std::shared_ptr<Job>>>&
                resultsPerJobMap,
            std::map<uint64_t, Archive*>& archiveMap);

        void evaluateAllRootsInParallelCompileResults(
            std::map<uint64_t, std::pair<std::shared_ptr<EvaluationResult>,
                                         std::shared_ptr<Job>>>&
                resultsPerJobMap,
            std::multimap<std::shared_ptr<EvaluationResult>,
                          const TPG::TPGVertex*>& results,
            std::map<uint64_t, Archive*>& archiveMap);

        void slaveEvalJobThread(
            uint64_t generationNumber, LearningMode mode,
            std::queue<std::shared_ptr<Learn::Job>>& jobsToProcess,
            std::mutex& rootsToProcessMutex,
            std::map<uint64_t, std::pair<std::shared_ptr<EvaluationResult>,
                                         std::shared_ptr<Job>>>&
                resultsPerRootMap,
            std::mutex& resultsPerRootMapMutex,
            std::map<uint64_t, Archive*>& archiveMap,
            std::mutex& archiveMapMutex, bool useMainEnvironment);

        void mergeArchiveMap(std::map<uint64_t, Archive*>& archiveMap);

      public:
        ParallelLearningAgent(
            LearningEnvironment& le, const Instructions::Set& iSet,
            const LearningParameters& p,
            const TPG::TPGFactory& factory = TPG::TPGFactory())
            : LearningAgent(le, iSet, p, factory)
        {
            maxNbThreads = p.nbThreads;
        };

        std::multimap<std::shared_ptr<EvaluationResult>, const TPG::TPGVertex*>
        evaluateAllRoots(uint64_t generationNumber, LearningMode mode) override;
    };
}

namespace {
    // Conversion function for std::shared_ptr
    template <class T>
    struct SharedPtrToPython {
        static PyObject* convert(const std::shared_ptr<T>& ptr) {
            boost::python::object obj(ptr);  // Increment the reference count
            PyObject* raw_ptr = boost::python::incref(obj.ptr());
            return raw_ptr;
        }
    };

    // Helper function to register conversion for std::shared_ptr
    template <class T>
    void registerSharedPtr() {
        boost::python::to_python_converter<std::shared_ptr<T>, SharedPtrToPython<T>>();
        boost::python::register_ptr_to_python<std::shared_ptr<T>>();
    }
}

BOOST_PYTHON_MODULE(parallelLearningAgent) {
    using namespace boost::python;
    using namespace Learn;

    registerSharedPtr<EvaluationResult>();

    class_<ParallelLearningAgent, boost::noncopyable, bases<LearningAgent>>(
        "ParallelLearningAgent", init<LearningEnvironment&, const Instructions::Set&, const LearningParameters&>())
        .def("evaluateAllRoots", &ParallelLearningAgent::evaluateAllRoots)
        ;
}
