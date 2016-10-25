/*********************************************************************
Matt Marchant 2016
http://trederia.blogspot.com

SuperTerrain - Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#ifndef ST_CHUNK_HPP_
#define ST_CHUNK_HPP_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include <array>

class Chunk final : public sf::Drawable
{
public:
    Chunk(sf::Vector2f position);
    ~Chunk() = default;

    std::uint64_t getID() const
    {
        //precalc this:
        //pos.x * pos.y + std::hash(pos.x > y ? "buns" : "dicketry") + std::hash(quadrant);
    }

    const sf::FloatRect& getGlobalBounds() const { return m_globalBounds; }
    const sf::Vector2f& getPosition() { return m_position; }

    static const sf::Vector2f& chunkSize();

    void destroy() { m_destroyed = true; } //TODO only mark true when thread not pending
    bool destroyed() const { return m_destroyed; }

private:
    
    bool m_destroyed;
    sf::Vector2f m_position;

    std::array<sf::Vertex, 4u> m_vertices;
    sf::FloatRect m_globalBounds;

    void draw(sf::RenderTarget&, sf::RenderStates) const override;
};

#endif //ST_CHUNK_HPP_