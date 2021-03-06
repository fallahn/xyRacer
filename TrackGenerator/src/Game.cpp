/******************************************************************

Matt Marchant 2016
http://trederia.blogspot.com

xyRacer - Zlib license.

This software is provided 'as-is', without any express or
implied warranty.In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions :

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.

******************************************************************/

#include <Game.hpp>
#include <RacingState.hpp>

#include <SFML/Window/Event.hpp>

Game::Game()
    : m_userInterface   (*this),
    m_stateStack({ getRenderWindow(), *this })
{
    setMouseCursorVisible(true);
}

//private
void Game::handleEvent(const sf::Event& evt)
{
    if (evt.type == sf::Event::KeyReleased)
    {
        switch (evt.key.code)
        {
        default: break;
        case sf::Keyboard::Escape:
            xy::App::quit();
            break;
        }
    }

    m_stateStack.handleEvent(evt);
}

void Game::handleMessage(const xy::Message& msg)
{
    m_stateStack.handleMessage(msg);
}

void Game::updateApp(float dt)
{
    m_stateStack.update(dt);
}

void Game::draw()
{
    m_stateStack.draw();
}

void Game::registerStates()
{
    m_stateStack.registerState<RacingState>(StateID::Racing);
}

void Game::initialise()
{
    registerStates();
    m_stateStack.pushState(StateID::Racing);
}

void Game::finalise()
{
    m_stateStack.clearStates();
    m_stateStack.applyPendingChanges();
}