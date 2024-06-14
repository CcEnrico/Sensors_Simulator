#include "Airqualitysensor.h"

namespace Sensor{

AirQualitySensor::AirQualitySensor(unsigned int id,
    std::string  n,
    unsigned int dn,
    EnviromentalConditions::AirQuality init,
    EnviromentalConditions::AirQuality stddev
    ):
    AbstractSensor(id, n, dn),
    initial(init),
    stdDeviation(stddev)
{
}

EnviromentalConditions::AirQuality AirQualitySensor::getAQInitial()const{
    return initial;
}

double AirQualitySensor::getInitialPm10()const{
    return initial.getPm10();
}

double AirQualitySensor::getInitialNO2()const{
    return initial.getNO2();
}

AirQualitySensor& AirQualitySensor::setAQInitial(const EnviromentalConditions::AirQuality init){
    this->initial = init;
    return *this;
}

AirQualitySensor& AirQualitySensor::setInitialPm10(const double pm10){
    this->initial.setPm10(pm10);
    return *this;
}

AirQualitySensor& AirQualitySensor::setInitialNO2(const double no2){
    this->initial.setNO2(no2);
    return *this;
}

EnviromentalConditions::AirQuality AirQualitySensor::getAQStdDeviation()const{
    return stdDeviation;
}

double AirQualitySensor::getStdDeviationPm10()const{
    return stdDeviation.getPm10();
}

double AirQualitySensor::getStdDeviationNO2()const{
    return stdDeviation.getNO2();
}

AirQualitySensor& AirQualitySensor::setAQStdDeviation(const EnviromentalConditions::AirQuality stddev){
    this->stdDeviation = stddev;
    return *this;
}

AirQualitySensor& AirQualitySensor::setStdDeviationPm10(const double pm10){
    this->stdDeviation.setPm10(pm10);
    return *this;
}

AirQualitySensor& AirQualitySensor::setStdDeviationNO2(const double no2){
    this->stdDeviation.setNO2(no2);
    return *this;
}

void AirQualitySensor::accept(SConstVisitor &visitor) const{
    visitor.visit(*this);
}
void AirQualitySensor::accept(SVisitor &visitor){
    visitor.visit(*this);
}

std::vector<double> AirQualitySensor::getAQDataPm10()const{
    std::vector<double> pm10_data;
    for (const auto & it : airQualityData){
        pm10_data.push_back( it.getPm10() );
    }
    return pm10_data;
}
std::vector<double> AirQualitySensor::getAQDataN02()const{
    std::vector<double> n02_data;
    for (const auto & it : airQualityData) {
        n02_data.push_back( it.getNO2() );
    }
    return n02_data;
}

std::vector<double> AirQualitySensor::getAQDataIAQ()const{
    std::vector<double> IAQ_data;
    for (const auto & it : airQualityData) {
        IAQ_data.push_back( it.getIndexAQ() );
    }
    return IAQ_data;
}

void AirQualitySensor::simulate(){

    airQualityData.push_back(initial);

    double current_pm10 = initial.getPm10();
    double current_n02 = initial.getNO2();

    std::random_device rand;
    std::mt19937 gen(rand());

    double data_std_dev_pm10 = stdDeviation.getPm10() / std::sqrt(static_cast<double>(dataNum));
    double data_std_dev_n02 = stdDeviation.getNO2() / std::sqrt(static_cast<double>(dataNum));


    std::normal_distribution<> distribution_pm10(0.0, data_std_dev_pm10);
    std::normal_distribution<> distribution_n02(0.0, data_std_dev_n02);

    for (unsigned int i = 0; i < dataNum; ++i) {

        current_pm10 += distribution_pm10(gen);
        current_n02 += distribution_n02(gen);;

        current_pm10 = std::max(0.0, current_pm10);
        current_n02 = std::max(0.0, current_n02);

        // e' un push back senza necessita' di costruire un oggetto temporaneo anonimo
        airQualityData.emplace_back(current_pm10, current_n02);

    }
}

void AirQualitySensor::clear(){
    airQualityData.clear();
}
void AirQualitySensor::modify(){

}

const EnviromentalConditions::AirQuality AirQualitySensor::optimal = EnviromentalConditions::AirQuality(0.0);
const EnviromentalConditions::AirQuality AirQualitySensor::good = EnviromentalConditions::AirQuality(50.0);
const EnviromentalConditions::AirQuality AirQualitySensor::acceptable = EnviromentalConditions::AirQuality(70.0);
const EnviromentalConditions::AirQuality AirQualitySensor::mediocre = EnviromentalConditions::AirQuality(100.0);
const EnviromentalConditions::AirQuality AirQualitySensor::poor = EnviromentalConditions::AirQuality(150.0);
const EnviromentalConditions::AirQuality AirQualitySensor::veryBad = EnviromentalConditions::AirQuality(200.0);


}

