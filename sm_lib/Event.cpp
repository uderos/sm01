#include "Event.h"

namespace udr {
namespace sm {

Event::Event(const int event_id, 
             const std::string & name) : 
  m_event_id(event_id),
  m_name(name)
{
}

int Event::GetId() const
{
  return m_event_id;
}

bool Event::IsTerminal() const
{
  return false;
}

std::string Event::to_string() const
{
  return std::string("EVENT_") + m_name;
}

} // namespace sm
} // namespace udr

