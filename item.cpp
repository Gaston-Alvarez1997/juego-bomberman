#include "item.h"


void item::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_spriteItem, states);
}

sf::FloatRect item::getBounds() const {
	return _spriteItem.getGlobalBounds();
}