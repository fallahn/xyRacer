/*********************************************************************
Matt Marchant 2016
http://trederia.blogspot.com

DoodleChum - Zlib license.

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

#ifndef DC_MUSIC_TASK_HPP_
#define DC_MUSIC_TASK_HPP_

#include <Task.hpp>

class MusicTask final : public Task
{
public:
    MusicTask(xy::Entity&, xy::MessageBus&, const sf::Vector2f&, bool);
    ~MusicTask() = default;

    void onStart() override;
    void update(float) override;

    Message::TaskEvent::Name getName() const override { return Message::TaskEvent::PlayMusic; }

private:
    float m_time;
    sf::Vector2f m_position;
    bool m_playFullTrack;
};

#endif //DC_MUSIC_TASK_HPP_