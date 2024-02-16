#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>

class CharacterAnimation
{
public:
    CharacterAnimation(int width = 800, int height = 600);
    ~CharacterAnimation();

    void drawBackground();
    void drawCharacter();
    void addSprite(sf::Sprite *sprite);
    void startAnimation();
    void keyboardEvent(sf::Event event);
    void mouseEvent(sf::Event event);
    void updateScreen();

private:
    std::vector<sf::Sprite *> mSprites;

    sf::RenderWindow *mWindow;

    int frame{};
    int counter{};
    int frameTime{3};
    int frameCounter{3};
};

#endif // __ANIMATION_H__
