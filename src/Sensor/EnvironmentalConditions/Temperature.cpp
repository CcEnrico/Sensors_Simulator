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

void Temperature::updateKelvin(){
    celsius = kelvin - 273.15;
    fahrenheit = (kelvin - 273.15)*(9/5)+32.0;
}

void Temperature::updateCelsius(){
    kelvin = celsius +273.15;
    fahrenheit = celsius*(9.0/5.0)+32.0;
}

void Temperature::updateFahrenheit(){
    celsius = (fahrenheit-32.0)*(9.0/5.0);
    kelvin = (fahrenheit-32.0)*(9.0/5.0)+273.15;
}

const double minK = 0;
const double minC = -273.15 ;
const double minF = -459.67;

}


