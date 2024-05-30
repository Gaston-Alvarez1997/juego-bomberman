#include "spritebloque.h"

Spritebloque::Spritebloque() {
    
    if (!_texturabloque.loadFromFile("imagenes/bloque.png")) {
        exit(10);
    }
    _spritebloque.setTexture(_texturabloque);
}
    sf::FloatRect Spritebloque::getBounds() const {
        return _spritebloque.getGlobalBounds();
    }

void Spritebloque::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_spritebloque, states);
}


