#include "Airquality.h"


namespace Sensor::EnviromentalConditions{

AirQuality::AirQuality( double pm_10,  double N_O2): pm10(pm_10), NO2(N_O2){
    updateAQ();
}

AirQuality::AirQuality( double IAQ): indexAQ(IAQ){
    updateValues();
}

double AirQuality::getPm10()const{
    return pm10;
}

AirQuality& AirQuality::setPm10(const double pm_10){
    this->pm10 = pm_10;
    updateAQ();
    return *this;
}

double AirQuality::getNO2()const{
    return NO2;
}

AirQuality& AirQuality::setNO2(const double N_O2){
    this->NO2 = N_O2;
    updateAQ();
    return *this;
}

double AirQuality::getIndexAQ()const{
    return indexAQ;
}

AirQuality& AirQuality::setIndexAQ(const double IAQ){
    this->indexAQ = IAQ;
    updateValues();
    return *this;
}

AirQuality::operator double() const{
    return indexAQ;
}

//AirQuality& AirQuality::operator=(const AirQuality& aq){
//    if (this != &aq){
//        indexAQ = aq.indexAQ;
//        pm10 = aq.pm10;
//        NO2 = aq.NO2;
//    }
//    return *this;
//}

void AirQuality::updateAQ(){
    double Ipm10 = (pm10 / indexLimitPm10) * 100.0 ;
    double INO2 = (NO2/ indexLimitNO2) * 100.0;
    if(Ipm10 >= INO2) {
        indexAQ = Ipm10;
    }else{
        indexAQ = INO2;
    }
}

void AirQuality::updateValues(){
    pm10 = (indexAQ / 100.0) * indexLimitPm10;;
    NO2 = (indexAQ / 100.0) * indexLimitNO2;
}

const double AirQuality::indexLimitPm10 = 50.0 ;    // micro_g/m3
const double AirQuality::indexLimitNO2 = 200.0 ;     // micro_g/m3

}


