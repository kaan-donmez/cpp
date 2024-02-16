#include "CharacterAnimation.h"

int main()
{
    CharacterAnimation *characterAnimation = new CharacterAnimation(800, 600);

    std::vector<sf::Sprite *> sprites;
    std::vector<sf::Texture *> textures;

    for (int i = 0; i < 3; i++)
    {
        std::string sprikeName = "/Users/kaandonmez/Documents/Software/Github/Cpp/SFML/Animation/Assets/Dead__0" + std::to_string(i) + ".png";

        sf::Texture *newtexture = new sf::Texture;
        sf::Sprite *newSprite = new sf::Sprite;

        if (!newtexture->loadFromFile(sprikeName))
        {
        }

        newSprite->setTexture(*newtexture);
        characterAnimation->addSprite(newSprite);
    }
    characterAnimation->startAnimation();

    return 0;
}
