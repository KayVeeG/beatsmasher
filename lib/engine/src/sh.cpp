#include <smash.h>
#include <sh.h>

static smash::ShaderAttributes *_shattr;
static smash::Canvas *_cvs;

void shAccess::setShattr(smash::ShaderAttributes& shattrref) {
    _shattr = &shattrref;
}

void shAccess::setCvs(smash::Canvas& cvsref) {
    _cvs = &cvsref;
}

void* gp(std::string name) {
    return _shattr->getPointer(name);
}

float gf(std::string name) {
    return _shattr->getFloat(name);
}

smash::Vector2 gv(std::string name) {
    return _shattr->getVector(name);
}

smash::Color gc(std::string name) {
    return _shattr->getColor(name);
}

void sp(std::string name, void* pointer) {
    _shattr->setPointer(name, pointer);
}

void sf(std::string name, float value) {
    _shattr->setFloat(name, value);
}

void sv(std::string name, smash::Vector2 value) {
    _shattr->setVector(name, value);
}

void sc(std::string name, smash::Color value) {
    _shattr->setColor(name, value);
}

void spxl(size_t x, size_t y, smash::Color color) {
    _cvs->setPixel(x, y, color);
}

smash::Color gpxl(size_t x, size_t y) {
    return _cvs->getPixel(x, y);
}

size_t gwidth() {
    return _cvs->getWidth();
}

size_t gheight() {
    return _cvs->getHeight();
}