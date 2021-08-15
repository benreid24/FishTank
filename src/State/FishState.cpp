#include <State/FishState.hpp>

#include <BLIB/Engine.hpp>
#include <BLIB/Util/Random.hpp>

namespace state
{
using bl::engine::Engine;

bl::engine::State::Ptr FishState::create() { return Ptr(new FishState()); }

const char* FishState::name() const { return "FishState"; }

void FishState::activate(Engine&) {
    const unsigned int n = bl::util::Random::get<unsigned int>(3, 10);
    fish.reserve(n);
    for (unsigned int i = 0; i < n; ++i) {
        fish.emplace_back(sf::Vector2f(bl::util::Random::get<float>(0.f, 800.f),
                                       bl::util::Random::get<float>(0.f, 800.f)));
    }
}

void FishState::deactivate(Engine&) { fish.clear(); }

void FishState::update(Engine&, float dt) {
    for (fish::Fish& f : fish) { f.update(dt); }
}

void FishState::render(Engine& engine, float lag) {
    engine.window().clear(sf::Color::Blue);
    for (fish::Fish& f : fish) { f.render(engine.window(), lag); }
    engine.window().display();
}

} // namespace state
