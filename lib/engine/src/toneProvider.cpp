// ToneProvider.cpp

#include "ToneProvider.h"

namespace smash
{
    ToneProvider::ToneProvider() : m_head(nullptr) {}

    ToneProvider::~ToneProvider()
    {
        while (m_head)
        {
            SpeakerNode* temp = m_head;
            m_head = m_head->next;
            delete temp;
        }
    }

    void ToneProvider::addSpeaker(std::shared_ptr<Speaker> speaker)
    {
        SpeakerNode* newNode = new SpeakerNode(speaker);
        if (!m_head)
        {
            m_head = newNode;
        }
        else
        {
            SpeakerNode* current = m_head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void ToneProvider::removeSpeaker(std::shared_ptr<Speaker> speaker)
    {
        if (!m_head) return;

        if (m_head->speaker == speaker)
        {
            SpeakerNode* temp = m_head;
            m_head = m_head->next;
            delete temp;
            return;
        }

        SpeakerNode* current = m_head;
        while (current->next)
        {
            if (current->next->speaker == speaker)
            {
                SpeakerNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void ToneProvider::play(int index, note_t note, int octave)
    {
        SpeakerNode* current = m_head;
        while (current)
        {
            if (current->speaker->getIndex() == index)
            {
                current->speaker->play(note, octave);
                return;
            }
            current = current->next;
        }
    }

    void ToneProvider::stop(int index)
    {
        SpeakerNode* current = m_head;
        while (current)
        {
            if (current->speaker->getIndex() == index)
            {
                current->speaker->stop();
                return;
            }
            current = current->next;
        }
    }
}
