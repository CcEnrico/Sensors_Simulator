#ifndef SENSOR_HUMIDITYSENSOR_H
#define SENSOR_HUMIDITYSENSOR_H

#include"AbstractSensor.h"
#include"EnvironmentalConditions/Humidity.h"
#include<vector>

namespace Sensor{

class HumiditySensor: public AbstractSensor
{
public:
    static const EnviromentalConditions::Humidity min;
    static const EnviromentalConditions::Humidity max;

private:
    EnviromentalConditions::Humidity initial;
    EnviromentalConditions::Humidity stdDeviation;
    double rain_probability;
    std::vector<EnviromentalConditions::Humidity> humidities;
    bool rain;
    std::vector<unsigned int> weather_rainy;

public:
    HumiditySensor( unsigned int id,
                    std::string  n,
                    unsigned int dn,
                    EnviromentalConditions::Humidity init,
                    EnviromentalConditions::Humidity stddev,
                    double rp
    );

    EnviromentalConditions::Humidity getHumInitial()const;
    HumiditySensor& setHumInitial(const EnviromentalConditions::Humidity init);
    EnviromentalConditions::Humidity getHumStdDeviation()const;
    HumiditySensor& setHumStdDeviation(const EnviromentalConditions::Humidity stddev);
    double getRainProbability()const;
    HumiditySensor& setProbability(const double rp);

    virtual void accept(SConstVisitor& visitor)const final;
    virtual void accept(SVisitor& visitor) final;

    std::vector<double> getHumData()const;
    std::vector<unsigned int> getWeatherRainy()const;

    void simulate() override;
    void clear() override;
    void modify() override;

};

}

#endif // HUMIDITYSENSOR_H
