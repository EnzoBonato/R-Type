#include "../../INCLUDE/ComponentsLibrary.hpp"

ComponentsLibrary::ComponentsLibrary()
{
    std::vector<iComponent *> player;
    cGraphical *pGraph = new cGraphical("assets/isaac.png", sf::IntRect(0, 0, 30, 30));
    pGraph->getSprite().scale(3, 3);
    pGraph->addAnimationLoop("stage1R", 2, 150, sf::IntRect(64, 0, 32, 26));
    pGraph->changeAnimationLoop("stage1R");
    player.emplace_back(pGraph);
    player.emplace_back(new cWeapon(10, 1.5));
    player.emplace_back(new cControllable);
    player.emplace_back(new cSpeed(0, 0, 5));
    player.emplace_back(new cCollision(collision1, 0.5, 5, 3));
    player.emplace_back(new cScene(eGameScene::GAME_SCENE));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(1, player));

    std::vector<iComponent *> tear;
    tear.emplace_back(new cGraphical("assets/tear.png", sf::IntRect(0, 0, 16, 16)));
    tear.emplace_back(new cSpeed(20, 0));
    tear.emplace_back(new cCollision(collision2, 0, 1, 1));
    tear.emplace_back(new cScene(eGameScene::GAME_SCENE));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(2, tear));
    
    std::vector<iComponent *> background;
    cGraphical *bgGraph = new cGraphical("assets/tileset.png", sf::IntRect(0, 0, 100000, 100000));
    bgGraph->getSprite().setScale(5, 5);
    bgGraph->getSprite().setTexture(bgGraph->getTexture());
    background.emplace_back(bgGraph);
    background.emplace_back(new cSpeed(-10, 0));
    background.emplace_back(new cScene(eGameScene::GAME_SCENE));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(3, background));

    std::vector<iComponent *> fog;
    cGraphical *fogGraph = new cGraphical("assets/fog.png", sf::IntRect(5, 5, 100000, 100000));
    fogGraph->getSprite().setScale(5, 5);
    fogGraph->getSprite().setTexture(fogGraph->getTexture());
    fog.emplace_back(fogGraph);
    fog.emplace_back(new cSpeed(-15, 0));
    fog.emplace_back(new cScene(eGameScene::GAME_SCENE));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(4, fog));

    std::vector<iComponent *> menu;
    cGraphical *mGraph = new cGraphical("assets/menu.png", sf::IntRect(0, 0, 480, 256));
    mGraph->getSprite().setScale({8, 8});
    menu.emplace_back(mGraph);
    menu.emplace_back(new cText("assets/font1.ttf", 80, sf::Color::Black, "TEST"));
    menu.emplace_back(new cScene(eGameScene::MENU_SCENE));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(5, menu));
     
    std::vector<iComponent*> charger;
    cGraphical *mCharger = new cGraphical("assets/charger.png", sf::IntRect(0, 0, 32, 32), 100, 4, LEFT_TO_RIGHT, "walk");
    mCharger->addAnimationLoop("attack", 1, 100, sf::IntRect(32 * 4, 0, 32, 32));
    mCharger->getSprite().setScale(4, 4);
    mCharger->getSprite().setPosition(2000, 500);
    charger.emplace_back(mCharger);
    charger.emplace_back(new cScene(eGameScene::GAME_SCENE));
    charger.emplace_back(new cBehaviour);
    charger.emplace_back(new cCollision(eCollisionType::collision3, 0.2, 2, 1));
    charger.emplace_back(new cSpeed(-10, 0));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(6, charger));

    std::vector<iComponent *> wave;
    cText *twave1 = new cText("assets/font1.ttf", 100, sf::Color::Red, "Round ");
    twave1->getText().setPosition(sf::Vector2f(800, 400));
    wave.emplace_back(twave1);
    wave.emplace_back(new cScene(eGameScene::GAME_SCENE));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(7, wave));

    std::vector<iComponent*> boss;
    cGraphical *mboss = new cGraphical("assets/charger.png", sf::IntRect(0, 0, 32, 32), 100, 4, LEFT_TO_RIGHT, "walk");
    mboss->getSprite().setScale(20, 20);
    mboss->getSprite().setPosition(1700, 200);
    boss.emplace_back(mboss);
    boss.emplace_back(new cScene(eGameScene::GAME_SCENE));
    charger.emplace_back(new cBehaviour);
    charger.emplace_back(new cCollision(eCollisionType::collision3, 0.5, 40, 1));
    boss.emplace_back(new cSpeed(-1, 0));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(8, boss));

    std::vector<iComponent *> lifebar_black;
    cShape *lifebar_black1 = new cShape(sf::Color::Black, sf::Vector2f(400, 34));
    lifebar_black1->getShape().setPosition(sf::Vector2f(750, 898));
    lifebar_black.emplace_back(lifebar_black1);
    lifebar_black.emplace_back(new cScene(eGameScene::GAME_SCENE));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(9, lifebar_black));

    std::vector<iComponent *> lifebar_red;
    cShape *lifebar_red1 = new cShape(sf::Color::Red, sf::Vector2f(350, 30));
    lifebar_red1->getShape().setPosition(sf::Vector2f(753, 900));
    lifebar_red.emplace_back(lifebar_red1);
    lifebar_red.emplace_back(new cScene(eGameScene::GAME_SCENE));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(10, lifebar_red));

    std::vector<iComponent *> skull;
    cGraphical *pskull = new cGraphical("assets/skull.png", sf::IntRect(0, 0, 30, 30));
    pskull->getSprite().scale(2, 2);
    pskull->getSprite().setPosition(sf::Vector2f(715, 890));
    skull.emplace_back(pskull);
    skull.emplace_back(new cScene(eGameScene::GAME_SCENE));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(11, skull));
    
    std::vector<iComponent *> otherPlayer;
    cGraphical *opGraph = new cGraphical("assets/isaac.png", sf::IntRect(0, 0, 30, 30));
    opGraph->getSprite().scale(3, 3);
    opGraph->addAnimationLoop("stage1R", 2, 150, sf::IntRect(64, 0, 32, 26));
    opGraph->changeAnimationLoop("stage1R");
    otherPlayer.emplace_back(pGraph);
    otherPlayer.emplace_back(new cWeapon(10, 1.5));
    otherPlayer.emplace_back(new cSpeed(0, 0, 5));
    otherPlayer.emplace_back(new cCollision(collision1, 0.5, 5, 3));
    otherPlayer.emplace_back(new cScene(eGameScene::GAME_SCENE));
    _library.insert(std::pair<size_t, std::vector<iComponent *>>(12, otherPlayer));
}

ComponentsLibrary::~ComponentsLibrary()
{
    
}

std::vector<iComponent *> ComponentsLibrary::getVectorComponents(size_t entity)
{
    std::vector<iComponent *> cpy;
    for (size_t i = 0; i != _library.at(entity).size(); i++) {
        cpy.push_back(_library.at(entity)[i]->clone());
    }
    return (cpy);
}