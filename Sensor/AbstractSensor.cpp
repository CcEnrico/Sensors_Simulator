
#include "AbstractSensor.h"

namespace Sensor{

    AbstractSensor(const unsigned int id, std::string  n, unsigned int dn, double d, double v): identifier(id), name(n), dataNum(dn), deviation(d), variance(v){}

}

