#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include"AbstractSensor.h"
#include"EnvironmentalConditions/Temperature.h"
#include<vector>

namespace Sensor{

class TemperatureSensor: public AbstractSensor{

    EnviromentalConditions::Temperature min;
    EnviromentalConditions::Temperature max;
    EnviromentalConditions::Temperature initial;
    EnviromentalConditions::Temperature target;
    std::vector<EnviromentalConditions::Temperature> temperatures;

public:

    TemperatureSensor(unsigned int id,
                      std::string  n,
                      unsigned int dn,
                      double d,
                      double v,
                      EnviromentalConditions::Temperature mn,
                      EnviromentalConditions::Temperature mx,
                      EnviromentalConditions::Temperature init,
                      EnviromentalConditions::Temperature t
    );

    EnviromentalConditions::Temperature getTempMin()const;
    TemperatureSensor& setTempMin(const EnviromentalConditions::Temperature min);

    EnviromentalConditions::Temperature getTempMax()const ;
    TemperatureSensor& setTempMax(const EnviromentalConditions::Temperature max);

    EnviromentalConditions::Temperature getTempInitial()const ;
    TemperatureSensor& setTempInitial(const EnviromentalConditions::Temperature inital);

    EnviromentalConditions::Temperature getTempTarget()const;
    TemperatureSensor& setTempTarget(const EnviromentalConditions::Temperature target);

    virtual void accept(SConstVisitor& visitor) override;
    virtual void accept(SVisitor& visitor) override;

    virtual void simulate() override;
    virtual void clear() override;
    virtual void modify() override;

};

}

#endif
