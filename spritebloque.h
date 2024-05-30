#pragma once
#include <SFML/Graphics.hpp>
#include "colisionable.h"

class Spritebloque : public sf::Drawable,public Colision {

public:

	sf::Texture _texturabloque;
	sf::Sprite _spritebloque;


	Spritebloque();

	void draw(sf::RenderTarget& target, sf::RenderStates) const override;

	sf::FloatRect getBounds() const override;

};
