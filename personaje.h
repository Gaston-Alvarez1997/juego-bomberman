#pragma once
#include <SFML/Graphics.hpp>
#include "colisionable.h"



class Personaje: public sf::Drawable,public Colision
{

private:

	sf::Texture _textura;
	sf::Sprite _sprite;
	float _frame;
	float _velocidad;
	sf::Vector2f _correguirPosicion;
	

public:
	
	/////////////////////
	Personaje();
	////////////////////
	void draw(sf::RenderTarget& target, sf::RenderStates) const override;
	////////////////////
	void movimiento();
	////////////////////
	void setSpritePosicion();
	void setCorreguirPosicion();

	sf::Vector2f getCorreguirPosicion();
	////////////////
	sf::FloatRect getBounds() const override;
	//////////////////
	void crearBomba();




};



