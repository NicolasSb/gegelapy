#include <boost/python.hpp>
#include "instructions/lambdaInstruction.h"

namespace Instructions
{
    // Factory function to create LambdaInstruction from Python
    template <typename First, typename... Rest>
    LambdaInstruction<First, Rest...>* createLambdaInstruction(std::function<double(First, Rest...)> function)
    {
        return new LambdaInstruction<First, Rest...>(function);
    }

    // Define the Boost.Python bindings for the LambdaInstruction class
    template <typename First, typename... Rest>
    void LambdaInstructionWrapper()
    {
        boost::python::class_<LambdaInstruction<First, Rest...>, boost::python::bases<Instruction>>("LambdaInstruction", boost::python::no_init)
            .def("__init__", boost::python::make_constructor(&createLambdaInstruction<First, Rest...>))
            // Add more member function bindings specific to LambdaInstruction
            ;
    }

    // Define the Boost.Python module and initialize the bindings
    BOOST_PYTHON_MODULE(lambdaInstruction)
    {
        LambdaInstructionWrapper<double>();
        LambdaInstructionWrapper<double, double>();
        LambdaInstructionWrapper<double, double, double>();
        LambdaInstructionWrapper<double[]>();
        // Add more instantiations for other template parameters if needed
    }
}