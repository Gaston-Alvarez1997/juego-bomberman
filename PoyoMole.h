#pragma once
#include <SFML/Graphics.hpp>
#include "colisionable.h"

class EnemigoPoyoMole : public sf::Drawable, public Colision {

private:
	sf::Texture _textura;
	sf::Sprite _spritepoyomole;
	sf::Vector2f _correguirPosicion;
	int _direccion;
	float _velocidad;
	float _frame;
	int _PuntosVida;

public:

	EnemigoPoyoMole();

	void setposicion();

	void PosicionInicial(float x, float y);

	void Movimiento(int numero);

	sf::FloatRect getBounds() const override;

	void draw(sf::RenderTarget& target, sf::RenderStates) const override;


};
