#include "CharacterAnimation.h"

CharacterAnimation::CharacterAnimation(int width, int height)
{
    sf::ContextSettings settings;

    settings.antialiasingLevel = 8;
    mWindow = new sf::RenderWindow(sf::VideoMode(width, height), "Character Animation", sf::Style::Default, settings);
}

CharacterAnimation::~CharacterAnimation()
{
    delete mWindow;
}

void CharacterAnimation::drawBackground()
{
    while (mWindow->isOpen())
    {
        sf::Event event;
        while (mWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow->close();
        }

        mWindow->clear();
        mWindow->display();
    }
}

void CharacterAnimation::addSprite(sf::Sprite *sprite)
{
    mSprites.push_back(sprite);
}

void CharacterAnimation::startAnimation()
{
    mWindow->setFramerateLimit(60);

    while (mWindow->isOpen())
    {
        drawCharacter();
        // updateScreen();
    }
}

void CharacterAnimation::drawCharacter()
{
    mWindow->clear(sf::Color::Blue);

    if (counter == frameCounter)
    {
        counter = 0;
        frame = (frame + 1) % frameCounter;
    }
    else
        counter++;
    mWindow->draw(*mSprites[frame]);

    mWindow->display();
}

void CharacterAnimation::updateScreen()
{
    sf::Event event;

    while (mWindow->pollEvent(event))
    {

        if (event.type == sf::Event::Closed)
            mWindow->close();
        keyboardEvent(event);
        mouseEvent(event);
    }
}

void CharacterAnimation::keyboardEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left)

            if (event.key.code == sf::Keyboard::Right)
            {
            }
    }
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Left)
        {
        }
    }
}
void CharacterAnimation::mouseEvent(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
        }
    }
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
        }
    }
    if (event.type == sf::Event::MouseMoved)
    {
    }
}