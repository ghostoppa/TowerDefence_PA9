#include "InputManager.hpp"

bool InputManager::IsSpriteClicked(sf::Sprite& spriteRef, sf::Mouse::Button button, sf::RenderWindow& window)
{
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect tempRect(spriteRef.getGlobalBounds().left,
            spriteRef.getGlobalBounds().top,
            spriteRef.getGlobalBounds().width,
            spriteRef.getGlobalBounds().height);
        if (tempRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }
    return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& w)
{
    return sf::Mouse::getPosition(w);
}