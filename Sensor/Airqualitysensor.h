#ifndef AIRQUALITYSENSOR_H
#define AIRQUALITYSENSOR_H

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
    EnviromentalConditions::AirQuality target;
    std::vector<EnviromentalConditions::AirQuality> airQualityData;

public:
    AirQualitySensor(unsigned int id,
                     std::string  n,
                     unsigned int dn,
                     double d,
                     double v,
                     EnviromentalConditions::AirQuality init,
                     EnviromentalConditions::AirQuality t
    );

    EnviromentalConditions::AirQuality getHumInitial()const;
    AirQualitySensor& setHumInitial(const EnviromentalConditions::AirQuality init);
    EnviromentalConditions::AirQuality getHumTarget()const;
    AirQualitySensor& setHumTargt(const EnviromentalConditions::AirQuality t);


    virtual void accept(SConstVisitor& visitor) override;
    virtual void accept(SVisitor& visitor) override;

    virtual void simulate() override;
    virtual void clear() override;
    virtual void modify() override;

};

}



#endif // AIRQUALITYSENSOR_H
