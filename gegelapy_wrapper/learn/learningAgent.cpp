#include <boost/python.hpp>
#include <learn/learningAgent.h>


namespace Learn
    {
    // Wrapper class for LearningAgent
    class LearningAgentWrapper
    {
    public:
        LearningAgentWrapper(Learn::LearningEnvironment &le, const Instructions::Set &iSet, const Learn::LearningParameters &p, const TPG::TPGFactory &factory = TPG::TPGFactory())
            : agent(le, iSet, p, factory) {}

        void expose()
        {
            // Expose LearningAgent methods
            boost::python::class_<Learn::LearningAgent>("LearningAgent", boost::python::no_init)
                .def("initialize", &Learn::LearningAgent::init);

            // Expose LearningAgentWrapper methods
            boost::python::class_<LearningAgentWrapper>("LearningAgentWrapper", boost::python::init<Learn::LearningEnvironment&, const Instructions::Set&, const Learn::LearningParameters&, const TPG::TPGFactory&>())
                .def("expose", &LearningAgentWrapper::expose);
        }

    private:
        Learn::LearningAgent agent;
    };

    // Expose LearningAgentWrapper class using Boost Python
    BOOST_PYTHON_MODULE(LearningAgentWrap)
    {
        boost::python::class_<LearningAgentWrapper>("LearningAgentWrapper", boost::python::init<Learn::LearningEnvironment&, const Instructions::Set&, const Learn::LearningParameters&, const TPG::TPGFactory&>())
            .def("expose", &LearningAgentWrapper::expose);
    }
}