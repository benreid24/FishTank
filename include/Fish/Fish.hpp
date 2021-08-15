#ifndef FISH_FISH_HPP
#define FISH_FISH_HPP

#include <BLIB/Resources.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace fish
{
class Fish {
public:
    Fish(const sf::Vector2f& pos);

    void update(float dt);
    void render(sf::RenderTarget& target, float lag);

private:
    sf::Vector2f position;
    bl::resource::Resource<sf::Texture>::Ref txtr;
    sf::Sprite sprite;
};

} // namespace fish

#endif
