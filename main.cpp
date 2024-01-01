#include <iostream>
#include "Levenshtein.h"
#include "DataReader.h"
#include "ClusterAnalysis.h"
#include "Constants.h"

int main() {
    DataReader dataReader(R"(F:\Code\cluster-cpp\resource\nodes-smoba-custom.data)");

    std::vector<FelixnEntity> felixnEntities;
    dataReader.ReadFelixnEntity(felixnEntities, 1000);

    ClusterAnalysis ano;

    for (int i = 0; i < 100; i++) {
        ano.analysis(felixnEntities);
        ano.summary();

        LEVEN_RATIO_LIMIT += 0.01;
    }


    return 0;
}
