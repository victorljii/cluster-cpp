//
// Created by victorljli on 2023/12/29.
//

#ifndef CLUSTER_CPP_FELIXNGROUP_H
#define CLUSTER_CPP_FELIXNGROUP_H

#include <vector>
#include <iostream>
#include "FelixnEntity.h"
#include "Levenshtein.h"

class FelixnGroup {
public:
    FelixnGroup() = default;

    void insert(FelixnEntity entity) {
        double newSum = 0;
        for (int i = 0; i < size; i++) {
            double ratio = Levenshtein::ratio(group[i].getFullPath(), entity.getFullPath());
            newSum += ratio;
            radioSum[i] += ratio;
        }

        size++;
        group.push_back(entity);
        radioSum.push_back(newSum);

        findCenter();
    }

    double calDist(FelixnEntity &entity) {
        return Levenshtein::ratio(entity.getFullPath(), group[center].getFullPath());
    }

    double centerDist() {
        return radioSum[center];
    }

    void display() {
        for (FelixnEntity entity : group) {
            std::cout << entity.getFullPath() << std::endl;
        }
    }

private:
    std::vector<FelixnEntity> group;
    std::vector<double> radioSum;
    int size;
    int center;

    void findCenter() {
        center = 0;
        if (size <= 2) {
            return;
        }

        for (int i = 1; i < size; i++) {
            if (radioSum[i] < radioSum[center]) {
                center = i;
            }
        }
    }
};

#endif //CLUSTER_CPP_FELIXNGROUP_H
