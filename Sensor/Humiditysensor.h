#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include"AbstractSensor.h"
#include"EnvironmentalConditions/Humidity.h"
#include<vector>

namespace Sensor{

class HumiditySensor: public AbstractSensor
{
    static const EnviromentalConditions::Humidity min;
    static const EnviromentalConditions::Humidity max;

    EnviromentalConditions::Humidity initial;
    EnviromentalConditions::Humidity target;
    std::vector<EnviromentalConditions::Humidity> humidities;

public:
    HumiditySensor( unsigned int id,
                    std::string  n,
                    unsigned int dn,
                    double d,
                    double v,
                    const EnviromentalConditions::Humidity initial,
                    const EnviromentalConditions::Humidity target
    );

    EnviromentalConditions::Humidity getHumInitial()const;
    HumiditySensor& setHumInitial(const EnviromentalConditions::Humidity init);
    EnviromentalConditions::Humidity getHumTarget()const;
    HumiditySensor& setHumTargt(const EnviromentalConditions::Humidity t);

    virtual void accept(SConstVisitor& visitor) override;
    virtual void accept(SVisitor& visitor) override;

    virtual void simulate() override;
    virtual void clear() override;
    virtual void modify() override;

};

}

#endif // HUMIDITYSENSOR_H
