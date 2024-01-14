#ifndef SENSOR_CONST_VISITOR_H
#define SENSOR_CONST_VISITOR_H

namespace Sensor {

class AirQualitySensor;
class HumiditySensor;
class TemperatureSensor;

class SConstVisitor {
public:
    virtual ~SConstVisitor() {}
    virtual void visit(const AirQualitySensor& aQSensor) = 0;
    virtual void visit(const HumiditySensor& HmSensor) = 0;
    virtual void visit(const TemperatureSensor& TmpSensor) = 0;
};

}

#endif
