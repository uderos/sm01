#include <sstream>
#include <stdexcept>
#include "State.h"

namespace udr {
namespace sm {

State::State(const std::string & name) : m_name(name)
{
}

bool State::IsTerminal() const
{
  return false;
}

std::string State::to_string() const
{
  return m_name;
}

StatePtr State::ProcessEvent(const Event & event)
{
  const auto p = m_event_haneler_map.find(event.GetId());

  if (p == m_event_handler_map.end())
  {
    std::ostringstream oss;
    oss << "State " << m_name 
        << ": Un-handled event " << event.to_string() 
        << " ID=" << event.GetId();
    throw std::runtime_error(oss.str());
  }

  return p->second(event);
}

void State::RegisterEventHandler(const Event & event, event_handler_t handler)
{
  const auto p = m_event_haneler_map.find(event.GetId());

  if (p != m_event_handler_map.end())
  {
    std::ostringstream oss;
    oss << "State " << m_name 
        << ": Duplicated handler for event " << event.to_string() 
        << " ID=" << event.GetId();
    throw std::runtime_error(oss.str());
  }

  m_event_handler.insert(std::make_pair(event.GetId(), handler);
}


} // namespace sm
} // namespace udr

