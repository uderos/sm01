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
}

void State::ExitState()
{
}

StatePtr State::ProcessEvent(const Event & event)
{
  std::cout << "[SMDBG]State_" << m_name << ": processing event " << event.to_string() << std::endl;

  if (m_ignore_event_list.find(event.GetId()) != m_ignore_event_list.end())
    return StatePtr();

  const auto p = m_event_handler_map.find(event.GetId());

  if (p == m_event_handler_map.end())
  {
    std::ostringstream oss;
    oss << "[SMDBG]State " << m_name 
        << ": Un-handled event " << event.to_string() 
        << " ID=" << event.GetId();
    throw std::runtime_error(oss.str());
  }

  StatePtr next_state = std::move(p->second(event));
  return std::move(next_state);
}

void State::RegisterEventHandler(const int event_id, event_handler_t handler)
{
  const auto p = m_event_handler_map.find(event_id);

  if (p != m_event_handler_map.end())
  {
    std::ostringstream oss;
    oss << "[SMDBG]State " << m_name 
        << ": Duplicated handler for event " << event_id;
    throw std::runtime_error(oss.str());
  }

  m_event_handler_map[event_id] = handler;
}

void State::SetIgnoreEventList(const std::vector<int> & event_list)
{
  m_ignore_event_list.clear();

  for (const auto id : event_list)
    m_ignore_event_list.insert(id);
}


} // namespace sm
} // namespace udr

