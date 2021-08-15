#include <Fish/Fish.hpp>

#include <BLIB/Engine/Resources.hpp>

namespace fish
{
namespace
{
const sf::Vector2f SPEED(9.f, 2.1f);
}

Fish::Fish(const sf::Vector2f& pos)
: position(pos)
, txtr(bl::engine::Resources::textures().load("Resources/fish/test.png").data) {
    sprite.setTexture(*txtr, true);
}

void Fish::update(float dt) { position += SPEED * dt; }

void Fish::render(sf::RenderTarget& target, float lag) {
    sprite.setPosition(position + SPEED * lag);
    target.draw(sprite);
}

} // namespace fish
