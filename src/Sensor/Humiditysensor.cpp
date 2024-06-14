#include "Humiditysensor.h"

namespace Sensor{

HumiditySensor::HumiditySensor(unsigned int id,
    std::string  n,
    unsigned int dn,
    EnviromentalConditions::Humidity init,
    EnviromentalConditions::Humidity stddev,
    double rp
    ):
    AbstractSensor(id,n,dn),
    initial(init),
    stdDeviation(stddev),
    rain_probability(rp)
{}


EnviromentalConditions::Humidity HumiditySensor::getHumInitial()const{
    return initial;
}

HumiditySensor& HumiditySensor::setHumInitial(const EnviromentalConditions::Humidity init){
    this->initial = init;
    return *this;
}
EnviromentalConditions::Humidity HumiditySensor::getHumStdDeviation()const{
    return stdDeviation;
}
HumiditySensor& HumiditySensor::setHumStdDeviation(const EnviromentalConditions::Humidity stddev){
    this->stdDeviation = stddev;
    return *this;
}

double HumiditySensor::getRainProbability()const{
    return rain_probability;
}

HumiditySensor& HumiditySensor::setProbability(const double rp){
    this->rain_probability = rp;
    return *this;
}

void HumiditySensor::accept(SConstVisitor &visitor) const{
    visitor.visit(*this);
}
void HumiditySensor::accept(SVisitor &visitor){
    visitor.visit(*this);
}

    std::vector<double> HumiditySensor::getHumData()const{
        std::vector<double> humidity_data;
        for (const auto & it : humidities) {
            humidity_data.push_back( it.getRelativeHumidity() );
        }
        return humidity_data;
    }
    std::vector<unsigned int> HumiditySensor::getWeatherRainy()const{
        std::vector<unsigned int> rainy_data;
        for (const auto & it : weather_rainy) {
            rainy_data.push_back( it );
        }
        return rainy_data;
    }


void HumiditySensor::simulate() {

    humidities.push_back(initial);
    rain = false;

    double current = initial.getRelativeHumidity();

    std::random_device rand;
    std::mt19937 gen(rand());

    double data_std_dev = stdDeviation.getRelativeHumidity() / std::sqrt(static_cast<double>(dataNum));

    std::normal_distribution<> distribution(0.0, data_std_dev);

    for (unsigned int i = 0; i < dataNum; ++i) {

        double noise = distribution(gen);


        std::uniform_real_distribution<> rain_p(0.0, 1.0);
        double randomValue = rain_p(gen);
        if (randomValue < (rain_probability / 100)) {
            rain = !rain;
            weather_rainy.push_back(i);
        }

        if (rain) {
            if (current > 100.0) {
                current = 100.0;
            } else if (current < 60.0) {
                current += std::abs(noise) * 10;
            }else{
                current += noise;
            }

        } else {
            if (current < 0.0) {
                current = 0.0;
            } else if (current > 20.0) {
                current -= std::abs(noise) * 10;
            }else{
                current += noise;
            }
        }

        humidities.emplace_back(current );

    }

}
void HumiditySensor::clear() {
    humidities.clear();
    weather_rainy.clear();
}
void HumiditySensor::modify() {

}


const EnviromentalConditions::Humidity HumiditySensor::min = EnviromentalConditions::Humidity(0.0);
const EnviromentalConditions::Humidity HumiditySensor::max = EnviromentalConditions::Humidity(100.0);

}

