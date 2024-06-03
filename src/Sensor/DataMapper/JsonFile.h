//
// Created by enrico on 01/05/24.
//

#ifndef SENSOR_DATA_MAPPER_JSON_FILE_H
#define SENSOR_DATA_MAPPER_JSON_FILE_H

#include <string>
#include <vector>

#include "../AbstractSensor.h"
#include "../Converter/Json/Json.h"
#include "../Converter/Json/Reader.h"

namespace Sensor {
    namespace DataMapper {

        class JsonFile {
        private:
            std::string path;
            Converter::Json::Json& converter;

        public:
            JsonFile(const std::string& path, Converter::Json::Json& converter);
            static JsonFile fromPath(const std::string& path);
            const std::string& getPath() const;
            JsonFile& setPath(const std::string& path);
            const Converter::Json::Json& getConverter() const;
            JsonFile& store(const std::vector<AbstractSensor*> items);
            std::vector<AbstractSensor*> load();
        };

    }
}

#endif  // SENSOR_DATA_MAPPER_JSON_FILE_H