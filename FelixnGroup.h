//
// Created by victorljli on 2023/12/29.
//

#ifndef CLUSTER_CPP_FELIXNGROUP_H
#define CLUSTER_CPP_FELIXNGROUP_H

#include <vector>
#include "FelixnEntity.h"

class FelixnGroup {
public:
    FelixnGroup() = default;

    void findCenter() {
        if (group.size() <= 2) {
            center = 0;
            return;
        }
    }

    // TODO: 深入理解右值引用
    void insert(FelixnEntity &&entity) {
        group.push_back(entity);


    }
private:
    std::vector<FelixnEntity> group;
    std::vector<double> radioSum;
    int center;
};

#endif //CLUSTER_CPP_FELIXNGROUP_H
