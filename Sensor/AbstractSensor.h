#ifndef ABSTRACT_SENSOR_H
#define ABSTRACT_SENSOR_H

#include<string>

namespace Sensor{

class AbstractSensor{
    private:
    unsigned int identifier;
    std::string name;
    unsigned int dataNum;
    double deviation;
    double variance;

public:
    AbstractSensor(unsigned int id, std::string  n, unsigned int dn, double d, double v);

    virtual ~AbstractSensor() = default;

    unsigned int getIdentifier() const;
    const std::string& getName() const;
    AbstractSensor& setName(const std::string s);
    unsigned int getDataNum() const;
    AbstractSensor& setDataNum(const unsigned int dn);
    double getDeviation()const;
    AbstractSensor& setDeviation(const double d);
    double getVariance()const;
    AbstractSensor& setVariance(const double v);

    virtual void accept(IConstVisitor& visitor) const = 0;
    virtual void accept(IVisitor& visitor) = 0;

    virtual void simulate() = 0;
    virtual void clear() = 0;
    virtual void modify() = 0;

};

}

#endif
