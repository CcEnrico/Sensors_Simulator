#ifndef SENSOR_AIRQUALITYSENSOR_H
#define SENSOR_AIRQUALITYSENSOR_H

#include"AbstractSensor.h"
#include"EnvironmentalConditions/Airquality.h"
#include<vector>

namespace Sensor{

class AirQualitySensor: public AbstractSensor
{
public:
    static const EnviromentalConditions::AirQuality optimal;
    static const EnviromentalConditions::AirQuality good;
    static const EnviromentalConditions::AirQuality acceptable;
    static const EnviromentalConditions::AirQuality mediocre;
    static const EnviromentalConditions::AirQuality poor;
    static const EnviromentalConditions::AirQuality veryBad;

private:
    EnviromentalConditions::AirQuality initial;
    EnviromentalConditions::AirQuality stdDeviation;
    EnviromentalConditions::AirQuality target;
    std::vector<EnviromentalConditions::AirQuality> airQualityData;

public:
    AirQualitySensor(unsigned int id,
                     std::string  n,
                     unsigned int dn,
                     EnviromentalConditions::AirQuality init,
                     EnviromentalConditions::AirQuality stddev,
                     EnviromentalConditions::AirQuality t
    );

    EnviromentalConditions::AirQuality getAQInitial()const;
    double getInitialPm10()const;
    double getInitialNO2()const;
    AirQualitySensor& setAQInitial(const EnviromentalConditions::AirQuality init);
    AirQualitySensor& setInitialPm10(const double pm10);
    AirQualitySensor& setInitialNO2(const double no2);

    EnviromentalConditions::AirQuality getAQStdDeviation()const;
    double getStdDeviationPm10()const;
    double getStdDeviationNO2()const;
    AirQualitySensor& setAQStdDeviation(const EnviromentalConditions::AirQuality stddev);
    AirQualitySensor& setStdDeviationPm10(const double pm10);
    AirQualitySensor& setStdDeviationNO2(const double no2);

    EnviromentalConditions::AirQuality getAQTarget()const;
    double getTargetPm10()const;
    double getTargetNO2()const;
    AirQualitySensor& setAQTarget(const EnviromentalConditions::AirQuality t);
    AirQualitySensor& setTargetPm10(const double pm10);
    AirQualitySensor& setTargetNO2(const double no2);

    virtual void accept(SConstVisitor& visitor)const final;
    virtual void accept(SVisitor& visitor) final;

    std::vector<double> getAQDataPm10()const;
    std::vector<double> getAQDataN02()const;
    std::vector<double> getAQDataIAQ()const;

    virtual void simulate() override;
    virtual void clear() override;
    virtual void modify() override;

};


}



#endif // AIRQUALITYSENSOR_H
