#include "Event.h"

namespace udr {
namespace sm {

Event::Event(const std::string & name) : 
  m_name(name)
{
}

std::string Event::to_string() const
{
  return std::string("EVENT_") + m_name;
}

} // namespace sm
} // namespace udr

