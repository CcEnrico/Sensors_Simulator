//
// Created by enrico on 01/05/24.
//

#ifndef SENSOR_REPOSITORY_I_REPOSITORY_H
#define SENSOR_REPOSITORY_I_REPOSITORY_H

#include <vector>

#include "../AbstractSensor.h"

namespace Sensor {
    namespace Repository {

        class IRepository {
        public:
            virtual ~IRepository() = default;
            virtual IRepository& create(AbstractSensor *item) = 0 ;
            virtual AbstractSensor* read(const unsigned int identifier) const = 0;
            virtual IRepository& update(AbstractSensor* item) = 0;
            virtual IRepository& remove(const unsigned int identifier) = 0;
            virtual std::vector<AbstractSensor*> readAll() const = 0;
        };

    }
}

#endif  // SENSOR_REPOSITORY_I_REPOSITORY_H