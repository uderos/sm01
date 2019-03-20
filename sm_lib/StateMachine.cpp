#include <stdexcept>
#include <sstream>

#include "Event.h"
#include "State.h"
#include "StateMachine.h"

namespace udr {
namespace sm {

StateMachine::StateMachine(const std::string & name, StatePtr intial_state) :
  m_name(name),
  m_current_state_ptr(std::move(intial_state))
{
}

State & StateMachine::GetCurrentState() const
{
  if (! m_current_state_ptr.get())
    throw std::runtime_error("Current state not available");

  return *(m_current_state_ptr.get());
}

std::string StateMachine::to_string() const
{
  std::ostringstream oss;
  oss << "SM:" << m_name
      << '-' << GetCurrentState().to_string();
  return oss.str();
}

StatePtr StateMachine::ProcessEvent(const Event & event)
{
  StatePtr next_state_ptr = GetCurrentState().ProcessEvent(event);

  if (next_state_ptr)
  {
    GetCurrentState().ExitState();
    m_state_transition(next_state_ptr);
    GetCurrentState().EnterState();
  }
}

void StateMachine::m_state_transition(StatePtr & next_state_ptr)
{
  m_current_state_ptr.reset();
  m_current_state_ptr.swap(next_state_ptr);
}

} // namespace sm
} // namespace udr

