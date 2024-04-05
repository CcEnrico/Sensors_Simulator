#ifndef SENSOR_HUMIDITYSENSOR_H
#define SENSOR_HUMIDITYSENSOR_H

#include"AbstractSensor.h"
#include"EnvironmentalConditions/Humidity.h"
#include<vector>

namespace Sensor{

class HumiditySensor: public AbstractSensor
{
    static const EnviromentalConditions::Humidity min;
    static const EnviromentalConditions::Humidity max;

    EnviromentalConditions::Humidity initial;
    EnviromentalConditions::Humidity stdDeviation;
    EnviromentalConditions::Humidity target;
    std::vector<EnviromentalConditions::Humidity> humidities;

public:
    HumiditySensor( unsigned int id,
                    std::string  n,
                    unsigned int dn,
                    double v,
                    EnviromentalConditions::Humidity init,
                    EnviromentalConditions::Humidity stddev,
                    EnviromentalConditions::Humidity t
    );

    EnviromentalConditions::Humidity getHumInitial()const;
    HumiditySensor& setHumInitial(const EnviromentalConditions::Humidity init);
    EnviromentalConditions::Humidity getHumStdDeviation()const;
    HumiditySensor& setHumStdDeviation(const EnviromentalConditions::Humidity stddev);
    EnviromentalConditions::Humidity getHumTarget()const;
    HumiditySensor& setHumTargt(const EnviromentalConditions::Humidity t);

    virtual void accept(SConstVisitor& visitor)const final;
    virtual void accept(SVisitor& visitor) final;

    virtual void simulate() override;
    virtual void clear() override;
    virtual void modify() override;

};

}

#endif // HUMIDITYSENSOR_H
