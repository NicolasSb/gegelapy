#include <boost/python.hpp>
#include <vector>
#include <functional>
#include <stdexcept>

#include <instructions/instruction.h>
#include <instructions/set.h>

namespace Instructions {

    class SetWrapper {
    public:
        SetWrapper() : set() {}

        bool add(const Instruction& instruction) {
            return set.add(instruction);
        }

        unsigned int getNbInstructions() const {
            return set.getNbInstructions();
        }

        const Instruction& getInstruction(uint64_t i) const {
            try {
                return set.getInstruction(i);
            } catch (const std::out_of_range& e) {
                PyErr_SetString(PyExc_IndexError, e.what());
                throw boost::python::error_already_set();
            }
        }

        unsigned int getMaxNbOperands() const {
            return set.getMaxNbOperands();
        }

    private:
        Set set;
    };

    BOOST_PYTHON_MODULE(setWrapper) {
        boost::python::class_<SetWrapper>("Set")
            .def(boost::python::init<>())
            .def("add", &SetWrapper::add)
            .def("getNbInstructions", &SetWrapper::getNbInstructions)
            .def("getInstruction", &SetWrapper::getInstruction,
                 boost::python::return_value_policy<boost::python::reference_existing_object>())
            .def("getMaxNbOperands", &SetWrapper::getMaxNbOperands);
    }
}