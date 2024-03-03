#ifndef ABSTRACT_SENSOR_H
#define ABSTRACT_SENSOR_H

#include<string>

#include "SConstVisitor.h"
#include "SVisitor.h"

namespace Sensor{

class AbstractSensor{
    private:
    unsigned int identifier;
    std::string name;
    unsigned int dataNum;
    double variance;

public:
    AbstractSensor(unsigned int id,
                   std::string  n,
                   unsigned int dn,
                   double v
    );

    virtual ~AbstractSensor();

    unsigned int getIdentifier() const;
    const std::string& getName() const;
    AbstractSensor& setName(const std::string s);
    unsigned int getDataNum() const;
    AbstractSensor& setDataNum(const unsigned int dn);
    double getVariance()const;
    AbstractSensor& setVariance(const double v);

    virtual void accept(SConstVisitor& visitor) const = 0;
    virtual void accept(SVisitor& visitor) = 0;

    virtual void simulate()= 0;
    virtual void clear() = 0;
    virtual void modify() = 0;


};

}

#endif
