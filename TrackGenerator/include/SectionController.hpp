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

#ifndef XYR_SECTION_CONTROLLER_HPP_
#define XYR_SECTION_CONTROLLER_HPP_

#include <xygine/components/Component.hpp>

class TrackSection;
class SectionController final : public xy::Component
{
public:
    SectionController(xy::MessageBus&, TrackSection&);
    ~SectionController() = default;

    xy::Component::Type type() const override { return xy::Component::Type::Script; }
    void entityUpdate(xy::Entity&, float) override;

private:
    TrackSection& m_trackSection;
};

#endif //XYR_SECTION_CONTROLLER_HPP_