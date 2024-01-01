//
// Created by victorljli on 2023/12/20.
//

#ifndef CLUSTER_CPP_FELIXNENTITY_H
#define CLUSTER_CPP_FELIXNENTITY_H

#include <string>
#include <utility>

class FelixnEntity {
public:
    FelixnEntity() = default;

    FelixnEntity(std::string _id, std::string _name, std::string _fullPath, long long _size) :
            id(std::move(_id)), name(std::move(_name)), fullPath(std::move(_fullPath)), size(_size) {}

    std::string getFullPath() {
        return fullPath;
    }
private:
    std::string id;
    std::string name;
    std::string fullPath;
    long long size = 0;
};


#endif //CLUSTER_CPP_FELIXNENTITY_H
