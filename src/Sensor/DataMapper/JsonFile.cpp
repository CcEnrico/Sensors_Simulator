//
// Created by enrico on 01/05/24.
//

#include "JsonFile.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <utility>

namespace Sensor::DataMapper {

    JsonFile::JsonFile(std::string  path, Converter::Json::Json& converter)
        :path(std::move(path)), converter(converter)
    {

    }
    JsonFile JsonFile::fromPath(const std::string& path){
        Converter::Json::Reader reader;
        Converter::Json::Json converter(reader);
        JsonFile data_mapper(path, converter);
        return data_mapper;
    }
    const std::string& JsonFile::getPath() const{
        return path;
    }
    JsonFile& JsonFile::setPath(const std::string& p){
        this->path = p;
        return *this;
    }
    const Converter::Json::Json& JsonFile::getConverter() const{
        return converter;
    }
    JsonFile& JsonFile::store(const std::vector<AbstractSensor*> sensors){
        QJsonArray json_items;
        for ( auto it = sensors.begin(); it != sensors.end(); it++ ) {
            json_items.push_back(converter.fromObject(**it));
        }
        QJsonDocument document(json_items);
        QFile json_file(path.c_str());
        json_file.open(QFile::WriteOnly);
        json_file.write(document.toJson());
        json_file.close();
        return *this;
    }
    std::vector<AbstractSensor*> JsonFile::load(){
        std::vector<AbstractSensor*> sensors;
        QFile json_file(path.c_str());
        json_file.open(QFile::ReadOnly);
        QByteArray data = json_file.readAll();
        json_file.close();
        QJsonDocument document = QJsonDocument::fromJson(data);
        QJsonArray json_items = document.array();

        for (const QJsonValue& value: json_items) {
            QJsonObject json_object = value.toObject();
            sensors.push_back(converter.toObject(json_object));
        }

        return sensors;

    }

}