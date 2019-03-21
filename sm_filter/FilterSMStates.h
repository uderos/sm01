#ifndef UDR_SM_FILTER_STATES_H
#define UDR_SM_FILTER_STATES_H

#include <sm_lib/State.h>

namespace udr {
namespace sm {
namespace filter_sm {



class DefaultState : public udr::sm::State
{
  protected:
    DefaultState(const std::string & name);

  private:
//  udr::sm::State::event_handler_t m_EOF_handler;
    udr::sm::StatePtr m_EOF_handler(const udr::sm::Event & event);
};


#define CREATE_STATE(NAME)                  \
class State##NAME : public DefaultState     \
{                                           \
  public:                                   \
    State##NAME () : DefaultState(#NAME) {} \
};

#define CREATE_TERMINAL_STATE(NAME)           \
class State##NAME : public DefaultState       \
{                                             \
  public:                                     \
    State##NAME () : DefaultState(#NAME) {}   \
    bool IsTerminal() const { return true; }  \
};


CREATE_STATE(WaitCmd);
CREATE_STATE(WaitCppNameArg);
CREATE_STATE(WaitArNameArg);
CREATE_STATE(WaitFileName);
CREATE_STATE(WaitEol);
CREATE_TERMINAL_STATE(TheEnd);

} // namespace filter_sm
} // namespace sm
} // namespace udr

#endif // UDR_SM_FILTER_STATES_H

