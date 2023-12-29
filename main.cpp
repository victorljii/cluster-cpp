#include <iostream>
#include "Levenshtein.h"
#include "DataReader.h"


int main() {
    DataReader dataReader(R"(D:\Code\cluster-cpp\resource\nodes-smoba-custom.data)");

    std::vector<FelixnEntity> felixnEntities;
    dataReader.ReadFelixnEntity(felixnEntities);



    return 0;
}
