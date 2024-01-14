#include "Airquality.h"

namespace Sensor{
namespace EnviromentalConditions{

AirQuality::AirQuality(const double pm_10, const double N_O2): pm10(pm_10), NO2(N_O2){
    updateAQ();
}

AirQuality::AirQuality(const double IAQ): indexAQ(IAQ){
    updateValues();
}

double AirQuality::getPm10()const{
    return pm10;
}

AirQuality& AirQuality::setPm10(const double pm_10){
    this->pm10 = pm_10;
    return *this;
}

double AirQuality::getNO2()const{
    return NO2;
}

AirQuality& AirQuality::setNO2(const double N_O2){
    this->NO2 = N_O2;
    return *this;
}

double AirQuality::getIndexAQ()const{
    return indexAQ;
}

AirQuality& AirQuality::setIndexAQ(const double IAQ){
    this->indexAQ = IAQ;
    return *this;
}

void AirQuality::updateAQ(){
    double Ipm10 = (pm10/indexLimitPm10) * 100;
    double INO2 = (NO2/indexLimitNO2) * 100;
    if(Ipm10 >= INO2) {
        indexAQ = Ipm10;
    }else{
        indexAQ = INO2;
    }
}

void AirQuality::updateValues(){
    double Ipm10 = indexAQ;
    double INO2 = indexAQ;
    pm10 = (Ipm10/100) * indexLimitPm10;
    NO2 = (INO2/100) * indexLimitNO2;
}

const double AirQuality::indexLimitPm10 = 50.0 ;    // micro_g/m3
const double AirQuality::indexLimitNO2 = 200.0 ;     // micro_g/m3

}
}

