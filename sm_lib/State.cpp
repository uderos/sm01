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
  return m_process_event(event);
}

void State::RegisterEventHandler(const Event & event, event_handler_t handler)
{
  const auto p = m_event_haneler_map.find(
}


} // namespace sm
} // namespace udr

