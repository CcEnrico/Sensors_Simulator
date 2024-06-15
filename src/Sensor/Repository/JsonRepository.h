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


namespace Sensor::Repository {

    class JsonRepository: public IRepository {
    private:
        DataMapper::JsonFile data_mapper;
        std::map<unsigned int, AbstractSensor*> repository;

    public:
        explicit JsonRepository(DataMapper::JsonFile data_mapper);
        ~JsonRepository() override;

        // warning: This static metod allocates memory (creates an onject JsonRepository) alloca memoria ocio
        static JsonRepository* fromPath(const std::string path);

        const DataMapper::JsonFile& getDataMapper() const;
        const std::map<unsigned int, AbstractSensor*>& getRepository() const;
        const std::string& getPath() const;
        JsonRepository& setPath(std::string path);
        JsonRepository& create(AbstractSensor* item) override;
        AbstractSensor* read(const unsigned int identifier) const override;
        JsonRepository& update(AbstractSensor* item) override;
        JsonRepository& remove(const unsigned int identifier) override;  // rimuove e dealloca
        virtual JsonRepository& erase(const unsigned int identifier); // rimuove senza deallocare
        virtual std::vector<AbstractSensor*> readAll() const;
        JsonRepository& store();
        bool empty() const;
    };

}


#endif //SENSOR_REPOSITORY_JSON_REPOSITORY_H
