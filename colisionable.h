#pragma once
#include <SFML/Graphics.hpp>

class Colision {

public:

	virtual sf::FloatRect getBounds() const = 0;

	bool escolisionable(Colision& col)const;

};


