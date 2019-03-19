#include "Event.h"

namespace udr {
namespace sm {

Event::Event(const std::string & name) : 
  m_name(name)
{
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

