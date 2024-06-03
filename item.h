#pragma once
#include <SFML/Graphics.hpp>
#include "colisionable.h"

class item : public sf::Drawable, public Colision {

private:

	sf::Texture apple;
	sf::Texture	icecream;
	sf::Texture cake;
	sf::Texture vidaextra;
	sf::Texture	skull;
	sf::Texture bombaextra;
	sf::Texture	explosionextra;
	sf::Sprite _spriteItem;

public:

	void draw(sf::RenderTarget& target, sf::RenderStates) const override;

	sf::FloatRect getBounds() const override;



};
