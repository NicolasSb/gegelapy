#include <boost/python.hpp>
#include <learn/learningEnvironment.h>

namespace Learn
{
    
    // Define the Boost.Python bindings for the Class
    BOOST_PYTHON_MODULE(learningEnvironmentWrap) {
        boost::python::class_<LearningEnvironment>("LearningEnvironment", boost::python::init<uint64_t>())
            // Add more member function bindings as needed
            ;
    }

}