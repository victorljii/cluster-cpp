//
// Created by victorljli on 2023/12/20.
//

#include "DataReader.h"

void DataReader::ReadFelixnEntity(std::vector<FelixnEntity> &result, int limit = -1) {
    std::ifstream ifs(path.c_str());

    if (!ifs.is_open()) {
        std::cout << "Open data json file fail." << std::endl;
        return;
    }

    Json::Reader jsonReader;
    std::string line;
    while (std::getline(ifs, line)) {
        if (limit > 0 && result.size() >= limit) {
            break;
        }
        std::istringstream iss(line);
        Json::Value rootValue;
        if (jsonReader.parse(iss, rootValue)) {
            FelixnEntity entity(rootValue["id"].asString(), rootValue["name"].asString(),
                                rootValue["fullPath"].asString(), rootValue["size"].asInt64());
            result.push_back(entity);
        } else {
            std::cout << "Parse data json file fail." << std::endl;
        }
    }

    ifs.close();
}