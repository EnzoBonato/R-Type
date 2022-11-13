#include "../../../INCLUDE/cGraphical.hpp"
#include <iostream> /// REMOVE !!

cGraphicalAnimation::cGraphicalAnimation(std::string name, int nbFrame, int64_t milli, sf::IntRect rect)
{
    _milliseconds = milli;
    _nbFrame = nbFrame;
    _name = name;
    _rect = rect;
}
cGraphicalAnimation::~cGraphicalAnimation() {}
std::string cGraphicalAnimation::name() {return (_name);}
sf::IntRect cGraphicalAnimation::rect() {return (_rect);}
int cGraphicalAnimation::nbFrame() {return (_nbFrame);}
int64_t cGraphicalAnimation::milliseconds() {return (_milliseconds);}

cGraphical::cGraphical(sf::String path, sf::IntRect rect, int64_t milliseconds, int nbFrame, direction_e dir/* = LEFT_TO_RIGHT*/, std::string namee /* = "DEFAULT"*/)
{
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(rect);
    _rect = rect;
    _clock.restart();
    _timingMilliseconds = milliseconds;
    _nbFrame = nbFrame;
    _dir = dir;
    _name = namee;
    if (namee != "DEFAULT" && namee != "") {
        cGraphicalAnimation toSave(namee, nbFrame, milliseconds, rect);
        _saved.push_back(toSave);
    }
    _checkedFrame = -1;
}

cGraphical::cGraphical(sf::Texture texture, sf::IntRect rect, int64_t milliseconds, int nbFrame, direction_e dir, std::string name)
{
    _texture = texture;
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(rect);
    _rect = rect;
    _clock.restart();
    _timingMilliseconds = milliseconds;
    _nbFrame = nbFrame;
    _dir = dir;
    _name = name;
    if (name != "DEFAULT" && name != "") {
        cGraphicalAnimation toSave(name, nbFrame, milliseconds, rect);
        _saved.push_back(toSave);
    }
    _checkedFrame = -1;
}

cGraphical::cGraphical(sf::Texture texture, sf::IntRect rect)
{
    _texture = texture;
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(rect);
    _rect = rect;
    _clock.restart();
    _timingMilliseconds = 100;
    _nbFrame = 1;
    _dir = LEFT_TO_RIGHT;
    _name = "";
    _checkedFrame = -1;
}

cGraphical::cGraphical(sf::String path, sf::IntRect rect)
{
    
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(rect);
    _texture.setRepeated(true);
    _rect = rect;
    _clock.restart();
    _timingMilliseconds = 100;
    _nbFrame = 1;
    _dir = LEFT_TO_RIGHT;
    _name = "";
    _checkedFrame = -1;
}


/// Problem : last frame is slightly longer.
int cGraphical::update()
{
    sf::Time curTime = _clock.getElapsedTime();
    
    if (curTime.asMilliseconds() / _timingMilliseconds > _nbFrame - 1) {
        if (_queue.size() > 1) {
            this->changeAnimationLoop(_queue[0]);
            _queue.erase(_queue.begin());
            return (update());
        }
        _clock.restart();
        _checkedFrame = -1;
        return (_nbFrame);
    }
    if (_dir == LEFT_TO_RIGHT)
        _sprite.setTextureRect(sf::IntRect(_rect.width * (curTime.asMilliseconds() / _timingMilliseconds) + _rect.left, _rect.top, _rect.width, _rect.height));    
    else if (_dir == TOP_TO_BOTTOM)
        _sprite.setTextureRect(sf::IntRect(_rect.left, _rect.width * (curTime.asMilliseconds() / _timingMilliseconds) + _rect.top, _rect.width, _rect.height));    
    if (_checkedFrame != curTime.asMilliseconds() / _timingMilliseconds)
        _checkedFrame = -1;
    return (curTime.asMilliseconds() / _timingMilliseconds);
}

void cGraphical::addAnimationLoop(std::string name, int nbFrame, int64_t milli, sf::IntRect rect)
{
    _saved.push_back(cGraphicalAnimation(name, nbFrame, milli, rect));
}

cGraphical::~cGraphical()
{}

void cGraphical::changeAnimationLoop(sf::IntRect rect, int64_t milliseconds, int nbFrame, std::string name/* = "DEFAULT"*/)
{
    _rect = rect;
    _timingMilliseconds = milliseconds;
    _nbFrame = nbFrame;
    _name = name;
    if (name != "DEFAULT" && name != "")
        _saved.push_back(cGraphicalAnimation(name, nbFrame, milliseconds, rect));
    _clock.restart();
}

void cGraphical::changeAnimationLoop(std::string name)
{
    if (name == _name)
        return;
    for (auto &i : _saved) {
        if (i.name() == name && _name != name) {
            _rect = i.rect();
            _timingMilliseconds = i.milliseconds();
            _nbFrame = i.nbFrame();
            _name = i.name();
            _clock.restart();
            _sprite.setTextureRect(_rect);
        }
    }
}

void cGraphical::display(sf::RenderWindow &window)
{
    window.draw(_sprite);
}

bool cGraphical::intersect(sf::Vector2f p)
{
    sf::IntRect r = this->getHitbox();
    if (p.x >= r.left && p.x <= r.left + r.width) {
        if (p.y >= r.top && p.y <= r.top + r.height) {
            return (true);
        }
    }
    return (false);
}

bool cGraphical::intersect(sf::Vector2i p)
{
    sf::IntRect r = this->getHitbox();

    if (p.x >= r.left && p.x <= r.left + r.width) {
        if (p.y >= r.top && p.y <= r.top + r.height) {
            return (true);
        }
    }
    return (false);
}

bool cGraphical::intersect(sf::Vector2u p)
{
    sf::IntRect r = this->getHitbox();

    if (r.left < 0 || r.top < 0 || r.width < 0 || r.height < 0)
        return (false); // Shouldn't be negative for better comparison.
    if (p.x >= (unsigned int)r.left && p.x <= (unsigned int)r.left + (unsigned int)r.width) {
        if (p.y >= (unsigned int)r.top && p.y <= (unsigned int)r.top + (unsigned int)r.height) {
            return (true);
        }
    }
    return (false);
}

bool cGraphical::intersect(sf::IntRect rect)
{
    if (this->intersect(sf::Vector2i{rect.left, rect.top}))
        return true;
    if (this->intersect(sf::Vector2i{rect.left + rect.width, rect.height}))
        return true;
    if (this->intersect(sf::Vector2i{rect.width, rect.top + rect.height}))
        return true;
    if (this->intersect(sf::Vector2i{rect.left + rect.width, rect.top + rect.height}))
        return true;
    return (false);
}

void cGraphical::addToQueue(std::string s)
{
    _queue.push_back(s);
}

sf::IntRect cGraphical::getHitbox()
{
    sf::IntRect result;
    sf::Vector2f sc = _sprite.getScale();
    sf::IntRect rect = this->_rect;
    sf::Vector2f pos = _sprite.getPosition();
    sf::Vector2f origin = _sprite.getOrigin();
    
    if (sc.x == 0)
        sc.x = 1;
    if (sc.y == 0)
        sc.y = 1;
    if (sc.y < 0) {
        result.height = rect.height * std::abs(sc.y);
        result.top = pos.y - (origin.y * sc.y) - rect.height * std::abs(sc.y);
    } else {
        result.height = rect.height * std::abs(sc.y);
        result.top = pos.y - (origin.y * sc.y);
    }
    if (sc.x < 0) {
        result.width = rect.width * std::abs(sc.x);
        result.left = pos.x - (origin.x * sc.x) - rect.width * std::abs(sc.x);
    } else {
        result.width = rect.width * std::abs(sc.x);
        result.left = pos.x - (origin.x * sc.x);
    }
    return (result);
}

sf::Sprite& cGraphical::getSprite()
{
    return _sprite;
}

std::string cGraphical::getName()
{
    return (_name);
}

int cGraphical::getNbFrame()
{
    return (_nbFrame);
}

int64_t cGraphical::getMilliseconds()
{
    return _timingMilliseconds;
}

sf::Clock cGraphical::getClock()
{
    return _clock;
}

sf::Texture cGraphical::getTexture()
{
    return _texture;
}

void cGraphical::synchronize(cGraphical toSynchronizeWith)
{
    this->_clock = toSynchronizeWith.getClock();
}

bool cGraphical::isActualFrame(int frame)
{
    if (_checkedFrame != -1)
        return false;
    int i = update();
    if (frame == i) {
        _checkedFrame = i;
        return true;
    }
    return false;
}

eComponentList cGraphical::getComponentType()
{
    return (eComponentList::graphical);
}

iComponent* cGraphical::clone()
{
    cGraphical *toRet = new cGraphical(_texture, _rect, _timingMilliseconds, _nbFrame, LEFT_TO_RIGHT, _name); 

    toRet->getSprite().setScale(this->getSprite().getScale());
    toRet->getSprite().setPosition(this->getSprite().getPosition());
    toRet->getSprite().setColor(this->getSprite().getColor());
    toRet->getSprite().setOrigin(this->getSprite().getOrigin());
    toRet->getSprite().setRotation(this->getSprite().getRotation());
    
    for (auto &i : _saved) {
        toRet->addAnimationLoop(i.name(), i.nbFrame(), i.milliseconds(), i.rect());
    }
    return toRet;
}