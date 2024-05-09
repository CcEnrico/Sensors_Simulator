//
// Created by enrico on 01/05/24.
//

#ifndef SENSOR_REPOSITORY_JSON_REPOSITORY_H
#define SENSOR_REPOSITORY_JSON_REPOSITORY_H

#include <string>
#include <map>

#include "IRepository.h"
#include "../DataMapper/JsonFile.h"
#include "../Converter/Json/Reader.h"

namespace Sensor {
    namespace Repository {

        class JsonRepository: public IRepository {
        private:
            DataMapper::JsonFile data_mapper;
            std::map<unsigned int, AbstractSensor*> repository;

        public:
            JsonRepository(DataMapper::JsonFile data_mapper);
            virtual ~JsonRepository();

            // warning: This static metod allocates memory (creates an onject JsonRepository)
            static JsonRepository* fromPath(const std::string path);

            const DataMapper::JsonFile& getDataMapper() const;
            const std::map<unsigned int, AbstractSensor*>& getRepository() const;
            const std::string& getPath() const;
            JsonRepository& setPath(std::string path);
            virtual JsonRepository& create(AbstractSensor* item);
            virtual AbstractSensor* read(const unsigned int identifier) const;
            virtual JsonRepository& update(AbstractSensor* item);
            virtual JsonRepository& remove(const unsigned int identifier);  // rimuove e dealloca
            virtual JsonRepository& erase(const unsigned int identifier); // rimuove senza deallocare
            virtual std::vector<AbstractSensor*> readAll() const;
            JsonRepository& store();
            bool empty();
        };

    }
}

#endif //SENSOR_REPOSITORY_JSON_REPOSITORY_H
