//
// Created by victorljli on 2023/12/20.
//

#ifndef CLUSTER_CPP_DATAREADER_H
#define CLUSTER_CPP_DATAREADER_H

#include <string>
#include <iostream>
#include <fstream>

#include "json/json.h"
#include "FelixnEntity.h"

class DataReader {
public:
    DataReader(std::string path_) {
        path = path_;
    }

    void ReadFelixnEntity(std::vector<FelixnEntity> &, int);

private:
    std::string path;
};


#endif //CLUSTER_CPP_DATAREADER_H
