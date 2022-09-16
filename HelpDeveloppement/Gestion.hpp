//
// Created by tcampagne on 03/06/22.
//

#ifndef YEP_400_ENTITYGESTION_HPP
#define YEP_400_ENTITYGESTION_HPP

#include <string>
#include "../MyRaylib.hpp"

class Gestion{
public:
    std::vector<float> getValueDataTransformEntity() {return valueDataTransformEntity;}
    void setValueDataTransformEntity(std::vector<float> newEntitiesName) {valueDataTransformEntity = newEntitiesName;}
    std::string getDirectoryRepo() {return directoryRepo;}
    void setDirectoryRepo(std::string newDir) {directoryRepo = newDir;}
    int getIndexTransform() {return indexTransform;}
    void setIndexTransform(int newIndexTransform) {indexTransform = newIndexTransform;}
    int getScrollSpeed() {return scrollSpeed;}
    void setScrollSpeed(int newScrollSpeed) {scrollSpeed = newScrollSpeed;}
    int getIndexSelectEntity() {return indexSelectEntity;}
    void setIndexSelectEntity(int newIndexSelectEntity) {indexSelectEntity = newIndexSelectEntity;}
    int getLetterCount() {return letterCount;}
    void setLetterCount(int newLetterCount) {letterCount = newLetterCount;}
    int getFramesCounter() {return framesCounter;}
    void setFramesCounter(int newFramesCounter) {framesCounter = newFramesCounter;}

private:
    std::string directoryRepo = GetPrevDirectoryPath(GetWorkingDirectory());
    int scrollSpeed = 4;
    int letterCount = 0;
    int indexSelectEntity = 0;
    int indexTransform = -1;
    int framesCounter = 0;
    std::vector<float> valueDataTransformEntity;
};

#endif //YEP_400_ENTITYGESTION_HPP
