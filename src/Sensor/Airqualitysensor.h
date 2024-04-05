#ifndef SENSOR_AIRQUALITYSENSOR_H
#define SENSOR_AIRQUALITYSENSOR_H

#include"AbstractSensor.h"
#include"EnvironmentalConditions/Airquality.h"
#include<vector>

namespace Sensor{

class AirQualitySensor: public AbstractSensor
{
    static const EnviromentalConditions::AirQuality optimal;
    static const EnviromentalConditions::AirQuality good;
    static const EnviromentalConditions::AirQuality acceptable;
    static const EnviromentalConditions::AirQuality mediocre;
    static const EnviromentalConditions::AirQuality poor;
    static const EnviromentalConditions::AirQuality veryBad;

    EnviromentalConditions::AirQuality initial;
    EnviromentalConditions::AirQuality stdDeviation;
    EnviromentalConditions::AirQuality target;
    std::vector<EnviromentalConditions::AirQuality> airQualityData;

public:
    AirQualitySensor(unsigned int id,
                     std::string  n,
                     unsigned int dn,
                     double v,
                     EnviromentalConditions::AirQuality init,
                     EnviromentalConditions::AirQuality stddev,
                     EnviromentalConditions::AirQuality t
    );

    EnviromentalConditions::AirQuality getAQInitial()const;
    AirQualitySensor& setAQInitial(const EnviromentalConditions::AirQuality init);
    EnviromentalConditions::AirQuality getAQStdDeviation()const;
    AirQualitySensor& setAQStdDeviation(const EnviromentalConditions::AirQuality stddev);
    EnviromentalConditions::AirQuality getAQTarget()const;
    AirQualitySensor& setAQTarget(const EnviromentalConditions::AirQuality t);


    virtual void accept(SConstVisitor& visitor)const final;
    virtual void accept(SVisitor& visitor) final;

    virtual void simulate() override;
    virtual void clear() override;
    virtual void modify() override;

};

}



#endif // AIRQUALITYSENSOR_H
