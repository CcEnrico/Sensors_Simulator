#include "Temperature.h"

namespace Sensor::EnviromentalConditions{

Temperature::Temperature(double temperature, char scale = 'c'){
    if(scale == 'k'){
        kelvin = temperature;
        updateKelvin();
    }else if(scale == 'c'){
        celsius = temperature;
        updateCelsius();
    }else if(scale == 'f'){
        fahrenheit = temperature;
        updateFahrenheit();
    }
}

Temperature::operator double() const{
    // default scale is celsius
    return celsius;
}

Temperature& Temperature::setKelvin(const double k){
    this->kelvin = k;
    updateKelvin();
    return *this;
}

double Temperature::getKelvin() const{
    return kelvin;
}

Temperature& Temperature::setCelsius(const double c){
    this->celsius = c;
    updateCelsius();
    return *this;
}

double Temperature::getCelsius() const{
    return celsius;
}

Temperature& Temperature::setFahrenheit(const double f){
    this->fahrenheit = f;
    updateFahrenheit();
    return *this;
}
double Temperature::getFahrenheit() const{
    return fahrenheit;
}

double Temperature::getTempscale(const char &scale) const {
    if (scale == 'c') return celsius;
    if (scale == 'f') return fahrenheit;
    if (scale == 'k') return kelvin;
    return 0;
}

void Temperature::updateKelvin(){
    celsius = kelvin - 273.15;
    fahrenheit = (kelvin - 273.15)*(9.0/5)+32.0;
}

void Temperature::updateCelsius(){
    kelvin = celsius +273.15;
    fahrenheit = celsius*(9.0/5.0)+32.0;
}

void Temperature::updateFahrenheit(){
    celsius = (fahrenheit - 32.0) * (5.0 / 9.0);
    kelvin = (fahrenheit + 459.67) * (5.0 / 9.0);
}

const double Temperature::minK = 0;
const double Temperature::minC = -273.15 ;
const double Temperature::minF = -459.67;

}


