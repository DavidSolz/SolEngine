#include "entity.h"

Entity::Entity(){
    this->meshID = 0;
}

template<typename... Child>
void Entity::addChild(const Child & ... child){
    children.emplace_back(std::make_unique<Entity>(child...));
    children.back()->parent = std::make_unique<Entity>(this);
}

void Entity::update(){

    if( transform.isDirty() ){
        forceUpdate();
        return;
    }

    for( auto && child : children){
        child->update();
    }

}

void Entity::forceUpdate(){

    if( parent ){
        transform.computeModelMatrix(parent->transform.getModelMatrix());
    }else{
        transform.computeModelMatrix();
    }

    for( auto && child : children){
        child->forceUpdate();
    }

}
