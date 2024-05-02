//
// Created by enrico on 01/05/24.
//

#include "JsonRepository.h"

namespace Sensor {
    namespace Repository {
        JsonRepository::JsonRepository(DataMapper::JsonFile data_mapper)
            : data_mapper(data_mapper)
        {
            std::vector<AbstractSensor*> sensor(data_mapper.load());
            for (auto it = sensor.begin(); it != sensor.end(); ++it){
                repository[(*it)->getIdentifier()] = *it;
            }

        }
        JsonRepository::~JsonRepository(){
            for (auto it = repository.begin(); it != repository.end(); ++it){
                delete it->second;
            }
        }
        JsonRepository JsonRepository::fromPath(const std::string path){

        }
        const DataMapper::JsonFile& JsonRepository::getDataMapper() const{

        }
        const std::map<unsigned int, AbstractSensor*>& JsonRepository::getRepository() const{

        }
        const std::string& JsonRepository::getPath() const{

        }
        JsonRepository& JsonRepository::setPath(std::string path){

        }
        JsonRepository& JsonRepository::create(AbstractSensor* sensor){
            repository[sensor->getIdentifier()] = sensor;
            return *this;
        }
        AbstractSensor* JsonRepository::read(const unsigned int identifier) const{

        }
        JsonRepository& JsonRepository::update(AbstractSensor* item){
            return create(item);
        }
        JsonRepository& JsonRepository::remove(const unsigned int identifier){

        }
        std::vector<AbstractSensor*> JsonRepository::readAll() const{
            std::vector<AbstractSensor*> sensors;
            for (auto it = repository.begin(); it != repository.end(); ++it ) {
                sensors.push_back(it->second);
            }
            return sensors;
        }
        JsonRepository& JsonRepository::store(){
            data_mapper.store(readAll());
            return *this;
        }

    } // Repository
} // Sensor