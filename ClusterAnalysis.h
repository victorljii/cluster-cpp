//
// Created by victorljli on 2023/12/29.
//

#ifndef CLUSTER_CPP_CLUSTERANALYSIS_H
#define CLUSTER_CPP_CLUSTERANALYSIS_H

#include <windows.h>
#include <vector>
#include <iostream>
#include "FelixnGroup.h"
#include "Constants.h"

class ClusterAnalysis {
public:
    void analysis(const std::vector<FelixnEntity> &entities) {
        LARGE_INTEGER t1, t2, tc;
        QueryPerformanceFrequency(&tc);
        QueryPerformanceCounter(&t1);

        int ind = 0;
        for (FelixnEntity entity: entities) {
            ind++;

            if (groups.empty()) {
                FelixnGroup *newGroup = new FelixnGroup();
                newGroup->insert(entity);
                groups.push_back(*newGroup);
                continue;
            }

            double min_dist = -1;
            int min_ind = -1;
            for (int i = 0; i < groups.size(); i++) {
                double dist = groups[i].calDist(entity);
                if (dist > LEVEN_RATIO_LIMIT) {
                    continue;
                }

                if (min_ind == -1 || dist < min_dist) {
                    min_ind = i;
                    min_dist = dist;
                }
            }

            if (min_ind != -1) {
                groups[min_ind].insert(entity);
            } else {
                FelixnGroup *newGroup = new FelixnGroup();
                newGroup->insert(entity);
                groups.push_back(*newGroup);
            }
        }

        QueryPerformanceCounter(&t2);
        double time = (double) (t2.QuadPart - t1.QuadPart) / tc.QuadPart;
        std::cout << "time = " << time << std::endl;
    }

    double summary() {
        double result = 0;
        for (FelixnGroup group : groups) {
            result += group.centerDist();
        }
        std::cout << "sum of dist: " << result << ", group num: " << groups.size() << std::endl;

        return result;
    }
private:
    std::vector<FelixnGroup> groups;
    double costTime;
};


#endif //CLUSTER_CPP_CLUSTERANALYSIS_H
