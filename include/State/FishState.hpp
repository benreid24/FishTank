#ifndef STATE_FISHSTATE_HPP
#define STATE_FISHSTATE_HPP

#include <BLIB/Engine/State.hpp>

namespace state
{
class FishState : public bl::engine::State {
public:
    static Ptr create();
    virtual ~FishState() = default;

    virtual const char* name() const override;
    virtual void activate(bl::engine::Engine& engine) override;
    virtual void deactivate(bl::engine::Engine& engine) override;

    virtual void update(bl::engine::Engine& engine, float dt) override;
    virtual void render(bl::engine::Engine& engine, float lag) override;

private:
    FishState();
};

} // namespace state

#endif
