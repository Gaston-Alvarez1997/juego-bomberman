#pragma once
#include <SFML/Graphics.hpp>
#include "colisionable.h"

class Spritesolido: public sf::Drawable,public Colision {

public:

	sf::Texture _texturasolido;
	sf::Sprite _spritesolido;


	Spritesolido();

	void draw(sf::RenderTarget& target, sf::RenderStates) const override;

	sf::FloatRect getBounds() const override;

};
