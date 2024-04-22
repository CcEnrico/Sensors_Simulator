#include"TemperatureSensor.h"

namespace Sensor {

TemperatureSensor::TemperatureSensor(unsigned int id,
    std::string  n,
    unsigned int dn,
    double v,
    EnviromentalConditions::Temperature mn,
    EnviromentalConditions::Temperature mx,
    EnviromentalConditions::Temperature init,
    EnviromentalConditions::Temperature stddev,
    EnviromentalConditions::Temperature t
):
    AbstractSensor(id,n,dn,v),
    min(mn),
    max(mx),
    initial(init),
    stdDeviation(stddev),
    target(t)
{}

EnviromentalConditions::Temperature TemperatureSensor::getTempMin()const{
    return min;
}
TemperatureSensor& TemperatureSensor::setTempMin(const EnviromentalConditions::Temperature m){
    this->min = m;
    return *this;
}

EnviromentalConditions::Temperature TemperatureSensor::getTempMax()const {
    return max;
}
TemperatureSensor& TemperatureSensor::setTempMax(const EnviromentalConditions::Temperature m){
    this->max = m;
    return *this;
}

EnviromentalConditions::Temperature TemperatureSensor::getStdDeviation()const {
    return stdDeviation;
}
TemperatureSensor& TemperatureSensor::setStdDeviation(const EnviromentalConditions::Temperature stddev){
    this->stdDeviation = stddev;
    return *this;
}

EnviromentalConditions::Temperature TemperatureSensor::getTempInitial()const {
    return initial;
}
TemperatureSensor& TemperatureSensor::setTempInitial(const EnviromentalConditions::Temperature init){
    this->initial = init;
    return *this;
}

EnviromentalConditions::Temperature TemperatureSensor::getTempTarget()const{
    return target;
}
TemperatureSensor& TemperatureSensor::setTempTarget(const EnviromentalConditions::Temperature t){
    this->target = t;
    return *this;
}

void TemperatureSensor::accept(SConstVisitor &visitor) const{
    visitor.visit(*this);
}
void TemperatureSensor::accept(SVisitor &visitor){
    visitor.visit(*this);
}

std::vector<double> TemperatureSensor::getTempDataMinCelsius()const{
    std::vector<double> min_data;
    for (const auto & it : min_temperatures){
        min_data.push_back( it.getCelsius() );
    }
    return min_data;
}
std::vector<double> TemperatureSensor::getTempDataMaxCelsius()const{
    std::vector<double> max_data;
    for (const auto & it : max_temperatures) {
        max_data.push_back( it.getCelsius() );
    }
    return max_data;
}
std::vector<double> TemperatureSensor::getTempDataMeanCelsius()const{
    std::vector<double> mean_data;
    for (const auto & it : mean_temperatures) {
        mean_data.push_back( it.getCelsius() );
    }
    return mean_data;
}

void TemperatureSensor::simulate() {

    min_temperatures.push_back(min);
    max_temperatures.push_back(max);
    mean_temperatures.push_back(initial);

    double current_min = min.getCelsius();
    double current_max = max.getCelsius();
    double current = initial.getCelsius();

    double dist_min = std::abs(current - current_min);
    double dist_max = std::abs(current_max - current);

    std::random_device rand;
    std::mt19937 gen(rand());
    std::normal_distribution<> distribution_min(0.0, stdDeviation.getCelsius());
    std::normal_distribution<> distribution_mean(0.0, stdDeviation.getCelsius());
    std::normal_distribution<> distribution_max(0.0, stdDeviation.getCelsius());

    for (unsigned int i = 0; i < dataNum; ++i) {
        // assumiamo di avere un ciclo giornaliero di 24 ore che dura 24 iterazioni"
        double sin_mean = std::sin(static_cast<double>(i) / 24 * 2 * M_PI);

        double noise_min = distribution_min(gen);
        double noise_mean = distribution_mean(gen);
        double noise_max = distribution_max(gen);

        current += noise_mean + sin_mean * 1.0;
        current_min = current - dist_min + noise_min;
        current_max = current + dist_max + noise_max;

        if (current_min > current_max) std::swap(current_min, current_max);

        min_temperatures.emplace_back(current_min, 'c');
        max_temperatures.emplace_back(current_max, 'c');
        mean_temperatures.emplace_back(current, 'c');

    }

}
void TemperatureSensor::clear() {
    min_temperatures.clear();
    max_temperatures.clear();
    mean_temperatures.clear();
}
void TemperatureSensor::modify() {

}



}
