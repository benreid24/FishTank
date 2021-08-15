#include <State/FishState.hpp>

namespace state
{
using bl::engine::Engine;

bl::engine::State::Ptr FishState::create() { return Ptr(new FishState()); }

FishState::FishState() {
    // TODO
}

const char* FishState::name() const { return "FishState"; }

void FishState::activate(Engine&) {}

void FishState::deactivate(Engine&) {}

void FishState::update(Engine&, float) {
    // TODO
}

void FishState::render(Engine&, float) {
    // TODO
}

} // namespace state
