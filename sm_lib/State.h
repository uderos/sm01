#ifndef UDR_SM_STATE_H
#define UDR_SM_STATE_H

#include <functional>
#include <memory>
#include <map>
#include "Event.h"

namespace udr {
namespace sm {

class State
{
  public:

    using event_handler_t = std::function<StatePtr(const Event &)>;

    State(const std::string & name);
    virtual ~State() = default;

    virtual StatePtr ProcessEvent(const Event & event);

    virtual bool IsTerminal() const;

    void RegisterEventHandler(const Event & event, event_handler_t handler);

    virtual std::string to_string() const;

  private:
    const std::string m_name;
    std::map<int, event_handler_t> m_event_handler_map;

    State(const State &) = delete;
    State(State &&) = delete;

    State & operator=(const State &) = delete;
    State & operator=(State &&) = delete;
    
    virtual StatePtr m_process_event(const Event & event) = 0;
};

using StatePtr = std::unique_ptr<State>;

#define CRETE_STATE(NAME)                                 \
class State#NAME : public State                           \
{                                                         \
  State#NAME() : State(NAME) {}                           \
  virtual StatePtr m_process_event(const Event & event);  \
};

} // namespace sm
} // namespace udr

#endif // UDR_SM_STATE_H
