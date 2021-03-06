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

#include <MusicTask.hpp>
#include <MessageIDs.hpp>

#include <xygine/Entity.hpp>
#include <xygine/Scene.hpp>
#include <xygine/Command.hpp>
#include <xygine/components/ParticleSystem.hpp>
#include <xygine/components/AudioSource.hpp>
#include <xygine/util/Random.hpp>

namespace
{
    const sf::Vector2f offset(126.f, -150.f);
    const float minMusicDuration = 30.f;
    const float maxMusicDuration = 360.f;
}

MusicTask::MusicTask(xy::Entity& e, xy::MessageBus& mb, const sf::Vector2f& position, bool playFull)
    :Task           (e, mb),
    m_time          (60.f),
    m_position      (position + offset),
    m_playFullTrack (playFull)
{

}

//public
void MusicTask::onStart()
{
    xy::Command cmd;
    cmd.category = Particle::Music;
    cmd.action = [this](xy::Entity& entity, float dt)
    {
        entity.setWorldPosition(m_position);
        entity.getComponent<xy::ParticleSystem>()->start();
    };
    getEntity().getScene()->sendCommand(cmd);

    //play a random track
    cmd.category = Command::MusicPlayer;
    cmd.action = [this](xy::Entity& entity, float)
    {
        auto musics = entity.getComponents<xy::AudioSource>();
        auto idx = (musics.size() == 1) ? 0 : xy::Util::Random::value(0, musics.size() - 1);
        if (m_playFullTrack) musics[idx]->stop(); //ensures track is rewound if paused
        musics[idx]->play();
        m_time = (m_playFullTrack) ? musics[idx]->getDuration() : minMusicDuration;
        m_time = std::min(m_time, maxMusicDuration); //limit to 6 minutes
    };
    getEntity().getScene()->sendCommand(cmd);

    auto msg = getMessageBus().post<Message::AnimationEvent>(Message::Animation);
    msg->id = Message::AnimationEvent::TV;
}

void MusicTask::update(float dt)
{
    float oldTime = m_time;
    m_time -= dt;

    if (oldTime > 1 && m_time < 1)
    {
        auto msg = getMessageBus().post<Message::AnimationEvent>(Message::Animation);
        msg->id = Message::AnimationEvent::TV;
    }

    if (m_time <= 0)
    {
        setCompleted(Message::TaskEvent::PlayMusic);

        xy::Command cmd;
        cmd.category = Particle::Music;
        cmd.action = [this](xy::Entity& entity, float dt)
        {
            entity.getComponent<xy::ParticleSystem>()->stop();
        };
        getEntity().getScene()->sendCommand(cmd);
    }
}