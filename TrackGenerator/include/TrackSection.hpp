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

#ifndef XYR_TRACK_SECTION_HPP_
#define XYR_TRACK_SECTION_HPP_

#include <xygine/Entity.hpp>
#include <xygine/physics/CollisionEdgeShape.hpp>

#include <SFML/Config.hpp>

#include <memory>
#include <map>

namespace xy
{
    class MessageBus;
    class MeshRenderer;
    class Material;
}

class TrackSection final
{    
public:
    using PointData = std::array<std::pair<std::vector<sf::Vector2f>, std::vector<sf::Vector2f>>, 6u>;

    explicit TrackSection(xy::MeshRenderer&);
    ~TrackSection() = default;

    void cacheParts(const std::vector<sf::Uint8>&);
    xy::Entity::Ptr create(xy::MessageBus&, float = 0.f);

    void update(float);

    void setTrackMaterial(const xy::Material& m) { m_trackMaterial = &m; }
    void setBarrierMaterial(const xy::Material& m) { m_barrierMaterial = &m; }

    static float getSectionSize();
    static float getSpeedIncrease();
private:

    xy::MeshRenderer& m_meshRenderer;

    std::size_t m_index;
    struct ModelID final
    {
        ModelID() = default;
        ModelID(sf::Uint8 i, std::size_t bo) : id(i), barrierOffset(bo) {}
        sf::Uint8 id = 0;
        std::size_t barrierOffset = 0;
    };
    std::vector<ModelID> m_uids;

    const xy::Material* m_trackMaterial;
    const xy::Material* m_barrierMaterial;

    float m_initialVelocity;
};

#endif //XYR_TRACK_SECTION_HPP_