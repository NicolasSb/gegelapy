#include <boost/python.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <mutator/rng.h>

namespace bp = boost::python;

namespace Mutator 
{
    BOOST_PYTHON_MODULE(rng)
    {
        bp::class_<Mutator::RNG, boost::shared_ptr<Mutator::RNG>>("RNG", bp::init<uint64_t>())
            .def("setSeed", &Mutator::RNG::setSeed)
            .def("getUnsignedInt64", &Mutator::RNG::getUnsignedInt64)
            .def("getInt32", &Mutator::RNG::getInt32)
            .def("getDouble", &Mutator::RNG::getDouble);
    }
}