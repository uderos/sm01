#ifndef UDR_SM_SM_H
#define UDR_SM_SM_H

#include <memory>
#include <string>

namespace udr {
namespace sm {

class Event; // forward declaration
class State; // forward declaration

class StateMachine
{
  public:
    virtual ~StateMachine() = default;

    StatePtr ProcessEvent(const Event & event);

    State & GetCurrentState() const;

    virtual std::string to_string() const;

  protected:

    StateMachine(const std::string & name, StatePtr intial_state);

  private:

    std::string m_name;
    StatePtr m_current_state_ptr;

    StateMachine(const StateMachine &) = delete;
    StateMachine(StateMachine &&) = delete;

    StateMachine & operator=(const StateMachine &) = delete;
    StateMachine & operator=(StateMachine &&) = delete;

    void m_state_transition(StatePtr & next_state_ptr);
};

} // namespace sm
} // namespace udr

#endif // UDR_SM_SM_H
