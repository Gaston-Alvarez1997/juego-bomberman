/*#pragma once
#include <SFML/Graphics.hpp>
#include "colisionable.h"

class CBomba : public sf::Drawable{

private:

	bool _estado;
	sf::Texture _texturaBomba;
	sf::Sprite _spriteBomba;
	float _frame;

public:

	CBomba();

	void setBombaPosicion(int x,int y);


	void animacionBomba();

	void draw(sf::RenderTarget& target, sf::RenderStates) const override;


};
*/