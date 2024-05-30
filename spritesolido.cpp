#include "spritesolido.h"


Spritesolido::Spritesolido() {
     if (!_texturasolido.loadFromFile("imagenes/solido.png")) {
        exit(10);
    }
     _spritesolido.setTexture(_texturasolido);
}
    sf::FloatRect Spritesolido::getBounds() const {
        return _spritesolido.getGlobalBounds();
    }

void Spritesolido::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_spritesolido, states);
}

