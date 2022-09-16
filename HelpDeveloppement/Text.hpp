//
// Created by tcampagne on 03/06/22.
//

#ifndef YEP_400_ENTITYTRANSFORMTEXT_HPP
#define YEP_400_ENTITYTRANSFORMTEXT_HPP

#include <string>
#include <vector>

class Text {
public:
    std::vector<std::string> getEntitiesName() {return entitiesName;}
    void setEntitiesName(std::vector<std::string> newEntitiesName) {entitiesName = newEntitiesName;}
    std::string getDataTransformEntity() {return dataTransformEntity;}
    void setDataTransformEntity(std::string newDataTransform) {dataTransformEntity = newDataTransform;}
    std::string getPathSaveDataTransformEntity() {return pathSaveDataTransformEntity;}
    void setPathSaveDataTransformEntity(std::string newPath) {pathSaveDataTransformEntity = newPath;}
    std::vector<std::string> getTransformValue () {return transformValue;}
    void setTransformValue(std::vector<std::string> newTransformValue) {transformValue = newTransformValue;}
    std::string getEntityTextSelected() {return entityTextSelected;}
    void setEntityTextSelected(std::string newEntityTextSelected) {entityTextSelected = newEntityTextSelected;}

private:
    std::vector<std::string> transformValue;
    std::string entityTextSelected;
    std::vector<std::string> entitiesName;
    std::string dataTransformEntity;
    std::string pathSaveDataTransformEntity;
};

#endif //YEP_400_ENTITYTRANSFORMTEXT_HPP
