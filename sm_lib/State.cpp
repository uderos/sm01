#include <iostream>
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

void State::EnterState()
{
  std::cout << "Entering state " << m_name << std::endl;
}

void State::ExitState()
{
  std::cout << "Exiting state " << m_name << std::endl;
}

StatePtr State::ProcessEvent(const Event & event)
{
  std::cout << "State_" << m_name << ": processing event " << event.to_string() << std::endl;

  const auto p = m_event_handler_map.find(event.GetId());

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

void State::RegisterEventHandler(const int event_id, event_handler_t handler)
{
  const auto p = m_event_handler_map.find(event_id);

  if (p != m_event_handler_map.end())
  {
    std::ostringstream oss;
    oss << "State " << m_name 
        << ": Duplicated handler for event " << event_id;
    throw std::runtime_error(oss.str());
  }

  m_event_handler_map[event_id] = handler;
}


} // namespace sm
} // namespace udr

