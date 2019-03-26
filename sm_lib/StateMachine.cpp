#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Event.h"
#include "OutMgr.h"
#include "State.h"
#include "StateMachine.h"

namespace udr {
namespace sm {

StateMachine::StateMachine(const std::string & name, StatePtr intial_state) :
  m_name(name),
  m_current_state_ptr(std::move(intial_state))
{
    m_enter_current_state();
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

void StateMachine::ProcessEvent(const Event & event)
{
  StatePtr next_state_ptr = GetCurrentState().ProcessEvent(event);

  if (next_state_ptr)
  {
    m_exit_current_state();
    m_state_transition(next_state_ptr);
    m_enter_current_state();
  }
}

void StateMachine::m_state_transition(StatePtr & next_state_ptr)
{
  g_DBGOUT << "[SMDBG]State Transition: " 
            << m_current_state_ptr->to_string() << " ==> "
            << next_state_ptr->to_string()
            << std::endl;
  m_current_state_ptr.reset();
  m_current_state_ptr.swap(next_state_ptr);
}

void StateMachine::m_enter_current_state() const
{
  g_DBGOUT << "[SMDBG]Entering state " << GetCurrentState().to_string() << std::endl;
  GetCurrentState().EnterState();
}

void StateMachine::m_exit_current_state() const
{
  g_DBGOUT << "[SMDBG]Leaving state " << GetCurrentState().to_string() << std::endl;
  GetCurrentState().ExitState();
}

} // namespace sm
} // namespace udr

