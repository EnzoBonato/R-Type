#include "../../../INCLUDE/cScene.hpp"

cScene::cScene(eGameScene e)
{
    _scene = e;
}

eComponentList cScene::getComponentType()
{
    return scene;
}

iComponent* cScene::clone()
{
    return new cScene(_scene);
}

eGameScene cScene::getScene()
{
    return _scene;
}

cScene::~cScene()
{

}
