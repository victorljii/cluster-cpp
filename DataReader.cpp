//
// Created by victorljli on 2023/12/20.
//

#include "DataReader.h"

void DataReader::ReadFelixnEntity(std::vector<FelixnEntity> &result) {
    std::ifstream ifs(path.c_str());

    if (!ifs.is_open()) {
        std::cout << "Open data json file fail." << std::endl;
        return;
    }

    Json::Reader jsonReader;
    std::string line;
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        Json::Value rootValue;
        if (jsonReader.parse(iss, rootValue)) {
            // std::string , std::string , int _size
            FelixnEntity entity(rootValue["id"].asString(), rootValue["name"].asString(),
                                rootValue["fullPath"].asString(), rootValue["size"].asInt64());
            result.push_back(entity);
        } else {
            std::cout << "Parse data json file fail." << std::endl;
        }
    }

    ifs.close();
}