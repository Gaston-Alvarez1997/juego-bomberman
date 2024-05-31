#pragma once
#include <SFML/Graphics.hpp>
#include "colisionable.h"

class CBomba : public sf::Drawable, public Colision {

private:

	sf::Texture _texturaBomba;
	sf::Texture _texturaexplosion;
	sf::Sprite _spriteBomba;
	float _frame;
	bool _viva;
	bool _estadoExplosion;


public:

	CBomba();

	void setBombaPosicion(int x, int y);
	void setestado(bool cambio);

	bool getestado();
	bool getexplision();

	void animacionBomba();
	

	void draw(sf::RenderTarget& target, sf::RenderStates) const override;

	sf::FloatRect getBounds() const override;

	
};
