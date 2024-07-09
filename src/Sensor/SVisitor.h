#ifndef SENSOR_VISITOR_H
#define SENSOR_VISITOR_H

namespace Sensor {

class AirQualitySensor;
class HumiditySensor;
class TemperatureSensor;

class SVisitor {
public:
    virtual ~SVisitor() = default;
    virtual void visit( AirQualitySensor& aQSensor) = 0;
    virtual void visit( HumiditySensor& HmSensor) = 0;
    virtual void visit( TemperatureSensor& TmpSensor) = 0;
};

}

#endif  // SENSOR_VISITOR_H
