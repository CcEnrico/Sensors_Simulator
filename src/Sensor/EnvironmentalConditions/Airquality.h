#ifndef SENSOR_ENVIROMENTALCONDITION_AIRQUALITY_H
#define SENSOR_ENVIROMENTALCONDITION_AIRQUALITY_H

namespace Sensor{

namespace EnviromentalConditions{

class AirQuality
{
    double indexAQ; // il massimo tra gli indici di IPM10=(dx / 50) x 100
                    //                              INO2=(dx / 200) x 100
    double pm10;    //  micro_g/m3 (micrograms per cubic meter) daily avarage
    double NO2;     //  micro_g/m3 (micrograms per cubic meter) hour avarage

public:
    AirQuality( double pm_10,
                double N_O2
    );
    AirQuality( double IAQ);

    double getPm10()const;
    AirQuality& setPm10(const double pm_10);
    double getNO2()const;
    AirQuality& setNO2(const double N_O2);
    double getIndexAQ()const;
    AirQuality& setIndexAQ(const double IAQ);

private:
    void updateAQ();
    void updateValues();

    static const double indexLimitPm10;    // micro_g/m3
    static const double indexLimitNO2;     // micro_g/m3
};

}

}

#endif // AIRQUALITY_H
