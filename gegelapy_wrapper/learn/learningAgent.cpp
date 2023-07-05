#include <boost/python.hpp>
#include <learn/learningAgent.h>

namespace Learn
{
    // Expose LearningAgentWrapper class using Boost Python
    BOOST_PYTHON_MODULE(LearningAgent)
    {
        boost::python::class_<LearningAgent, boost::noncopyable>("LearningAgentWrapper", boost::python::init<Learn::LearningEnvironment&, const Instructions::Set&, const Learn::LearningParameters&, const TPG::TPGFactory&>())
            .def("initialize", &Learn::LearningAgent::init);
            //other methods if required 
    }
}