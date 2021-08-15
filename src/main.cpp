#include <BLIB/Engine.hpp>
#include <BLIB/Logging.hpp>
#include <Properties.hpp>
#include <State/FishState.hpp>

int main() {
    BL_LOG_INFO << "Loading application properties";
    if (!Properties::load()) {
        BL_LOG_ERROR << "Failed to load application properties";
        return 1;
    }

    BL_LOG_INFO << "Creating engine instance";
    const bl::engine::Settings engineSettings =
        bl::engine::Settings()
            .withVideoMode(sf::VideoMode(800, 600, 32))
            .withWindowStyle(sf::Style::Close | sf::Style::Titlebar)
            .withWindowTitle("BLIB Project")
            .withWindowIcon("Resources/icon.png");
    bl::engine::Engine engine(engineSettings);
    BL_LOG_INFO << "Created engine";

    BL_LOG_INFO << "Running engine main loop";
    if (!engine.run(state::FishState::create())) {
        BL_LOG_ERROR << "Engine exited with error";
        return 1;
    }

    BL_LOG_INFO << "Exiting normally";
    return 0;
}
