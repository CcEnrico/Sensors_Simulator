#ifndef SENSOR_TEMPERATURESENSOR_H
#define SENSOR_TEMPERATURESENSOR_H

#include"AbstractSensor.h"
#include"EnvironmentalConditions/Temperature.h"
#include<vector>

namespace Sensor{

class TemperatureSensor: public AbstractSensor{

    EnviromentalConditions::Temperature min;
    EnviromentalConditions::Temperature max;
    EnviromentalConditions::Temperature initial;
    EnviromentalConditions::Temperature stdDeviation;
    EnviromentalConditions::Temperature target;
    std::vector<EnviromentalConditions::Temperature> mean_temperatures;
    std::vector<EnviromentalConditions::Temperature> min_temperatures;
    std::vector<EnviromentalConditions::Temperature> max_temperatures;

    char simulation_scale;

public:

    TemperatureSensor(unsigned int id,
                      std::string  n,
                      unsigned int dn,
                      double v,
                      EnviromentalConditions::Temperature mn,
                      EnviromentalConditions::Temperature mx,
                      EnviromentalConditions::Temperature init,
                      EnviromentalConditions::Temperature stddev,
                      EnviromentalConditions::Temperature t,
                      char simulation_scale
    );
    char getSimulationScale()const;
    TemperatureSensor& setSimulationScale(const char m);

    EnviromentalConditions::Temperature getTempMin()const;
    TemperatureSensor& setTempMin(const EnviromentalConditions::Temperature m);

    EnviromentalConditions::Temperature getTempMax()const ;
    TemperatureSensor& setTempMax(const EnviromentalConditions::Temperature m);

    EnviromentalConditions::Temperature getStdDeviation()const ;
    TemperatureSensor& setStdDeviation(const EnviromentalConditions::Temperature stddev);

    EnviromentalConditions::Temperature getTempInitial()const ;
    TemperatureSensor& setTempInitial(const EnviromentalConditions::Temperature init);

    EnviromentalConditions::Temperature getTempTarget()const;
    TemperatureSensor& setTempTarget(const EnviromentalConditions::Temperature t);

    virtual void accept(SConstVisitor& visitor)const final;
    virtual void accept(SVisitor& visitor) final;

    std::vector<double> getTempDataMin()const;
    std::vector<double> getTempDataMax()const;
    std::vector<double> getTempDataMean()const;

    virtual void simulate() override;
    virtual void clear() override;
    virtual void modify() override;

};

}

#endif
