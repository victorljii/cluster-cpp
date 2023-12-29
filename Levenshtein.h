//
// Created by victorljli on 2023/12/20.
//

#ifndef CLUSTER_CPP_LEVENSHTEIN_H
#define CLUSTER_CPP_LEVENSHTEIN_H

#include <string>

class Levenshtein {
public:
    double ratio(const std::string &str1, const std::string &str2);
    int dist(const std::string &str1, const std::string &str2);

};


#endif //CLUSTER_CPP_LEVENSHTEIN_H
