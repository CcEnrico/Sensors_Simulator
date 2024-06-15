#include"TemperatureSensor.h"

#include <utility>

namespace Sensor {

TemperatureSensor::TemperatureSensor(unsigned int id,
    std::string  n,
    unsigned int dn,
    EnviromentalConditions::Temperature mn,
    EnviromentalConditions::Temperature mx,
    EnviromentalConditions::Temperature init,
    EnviromentalConditions::Temperature stddev,
    unsigned int collection_per_day,
    char simulation_scale
):
    AbstractSensor(id,std::move(n),dn),
    min(mn),
    max(mx),
    initial(init),
    stdDeviation(stddev),
    collection_per_day(collection_per_day),
    simulation_scale(simulation_scale)
{}

char TemperatureSensor::getSimulationScale()const{
    return simulation_scale;
}

TemperatureSensor& TemperatureSensor::setSimulationScale(const char s){
    this->simulation_scale = s;
    return *this;
}

unsigned int TemperatureSensor::getCollectionPerDay() const{
    return collection_per_day;
}

TemperatureSensor& TemperatureSensor::setCollectionPerDay(const unsigned int cd){
    this->collection_per_day = cd;
    return *this;
}

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

void TemperatureSensor::accept(SConstVisitor &visitor) const{
    visitor.visit(*this);
}

void TemperatureSensor::accept(SVisitor &visitor){
    visitor.visit(*this);
}

std::vector<double> TemperatureSensor::getTempDataMin()const{
    std::vector<double> min_data;
    for (const auto & it : min_temperatures){
        min_data.push_back( it.getTempscale(simulation_scale) );
    }
    return min_data;
}

std::vector<double> TemperatureSensor::getTempDataMax()const{
    std::vector<double> max_data;
    for (const auto & it : max_temperatures) {
        max_data.push_back( it.getTempscale(simulation_scale) );
    }
    return max_data;
}

std::vector<double> TemperatureSensor::getTempDataMean()const{
    std::vector<double> mean_data;
    for (const auto & it : mean_temperatures) {
        mean_data.push_back( it.getTempscale(simulation_scale) );
    }
    return mean_data;
}

void TemperatureSensor::simulate() {

    min_temperatures.push_back(min);
    max_temperatures.push_back(max);
    mean_temperatures.push_back(initial);

    double current_min = min.getTempscale(simulation_scale);
    double current_max = max.getTempscale(simulation_scale);
    double current = initial.getTempscale(simulation_scale);
    double absolute_zero = -273.15;
    if (simulation_scale == 'c') absolute_zero = EnviromentalConditions::Temperature::minC;
    if (simulation_scale == 'f') absolute_zero = EnviromentalConditions::Temperature::minF;
    if (simulation_scale == 'k') absolute_zero = EnviromentalConditions::Temperature::minK;

    std::random_device rand;
    std::mt19937 gen(rand());

    double data_std_dev = stdDeviation.getTempscale(simulation_scale) / std::sqrt(static_cast<double>(dataNum));

    std::normal_distribution<> distribution_min(0.0, data_std_dev);
    std::normal_distribution<> distribution_mean(0.0, data_std_dev);
    std::normal_distribution<> distribution_max(0.0, data_std_dev);

    double dist_min = std::abs(current - current_min);
    double dist_max = std::abs(current_max - current);

    for (unsigned int i = 0; i < dataNum; ++i) {
        // assumiamo di avere un ciclo giornaliero
        double sin_mean = std::sin((static_cast<double>(i) / collection_per_day) * 2 * M_PI);

        double noise_min = distribution_min(gen);
        double noise_mean = distribution_mean(gen);
        double noise_max = distribution_max(gen);

        current += (noise_mean + sin_mean) ;
        current_min = current - dist_min + noise_min;
        current_max = current + dist_max + noise_max;

        // controllo di massimi minimi e zero assoluti
        if (current < absolute_zero) current = absolute_zero;
        if (current_min < absolute_zero) current_min = absolute_zero;
        if (current_max < absolute_zero) current_max = absolute_zero;

        if (current_min > current_max) std::swap(current_min, current_max);

        min_temperatures.emplace_back(current_min, simulation_scale);
        max_temperatures.emplace_back(current_max, simulation_scale);
        mean_temperatures.emplace_back(current, simulation_scale);

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
