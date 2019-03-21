#ifndef UDR_SM_STATE_H
#define UDR_SM_STATE_H

#include <functional>
#include <map>
#include <memory>
#include <set>
#include <vector>
#include "Event.h"

namespace udr {
namespace sm {

class State;
using StatePtr = std::unique_ptr<State>;

class State
{
  public:

    using event_handler_t = std::function<StatePtr(const Event &)>;

    virtual ~State() = default;

    virtual void EnterState();

    virtual void ExitState();

    virtual StatePtr ProcessEvent(const Event & event);

    virtual bool IsTerminal() const;

    void RegisterEventHandler(const int event_id, event_handler_t handler);

    void SetIgnoreEventList(const std::vector<int> & event_list);

    virtual std::string to_string() const;

  protected:
    State(const std::string & name);

  private:
    const std::string m_name;
    std::map<int, event_handler_t> m_event_handler_map;
    std::set<int> m_ignore_event_list;

    State(const State &) = delete;
    State(State &&) = delete;

    State & operator=(const State &) = delete;
    State & operator=(State &&) = delete;
};


} // namespace sm
} // namespace udr

#endif // UDR_SM_STATE_H
