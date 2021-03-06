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

#ifndef TG_SANDBOX_HPP_
#define TG_SANDBOX_HPP_

#include <TrackSection.hpp>

#include <xygine/Scene.hpp>
#include <xygine/physics/World.hpp>
#include <xygine/mesh/MeshRenderer.hpp>
#include <xygine/ShaderResource.hpp>
#include <xygine/mesh/MaterialResource.hpp>
#include <xygine/Resource.hpp>

#include <SFML/Graphics/Drawable.hpp>

namespace xy
{
    class Message;
    class MessageBus;
}

namespace sf
{
    class Event;
}

class UserInterface;
class Sandbox final : public sf::Drawable
{
public:
    Sandbox(xy::MessageBus&, UserInterface&, sf::RenderWindow&);
    ~Sandbox();

    void update(float);
    void handleEvent(const sf::Event&);
    void handleMessage(const xy::Message&);

private:

    xy::MessageBus& m_messageBus;
    UserInterface& m_ui;
    sf::RenderWindow& m_renderWindow;
    xy::Scene m_scene;
    xy::Physics::World m_physWorld;

    xy::MeshRenderer m_meshRenderer;
    TrackSection m_trackSection;

    xy::ShaderResource m_shaderResource;
    xy::MaterialResource m_materialResource;
    xy::TextureResource m_textureResource;

    void draw(sf::RenderTarget&, sf::RenderStates) const override;
    void updateFileList();
    void initScene();
};

#endif //TG_SANDBOX_HPP_