#ifndef UDR_SM_FILTER_STATES_H
#define UDR_SM_FILTER_STATES_H

#include <sm_lib/State.h>

namespace udr {
namespace sm {
namespace filter_rm {

#define CREATE_STATE(NAME)                  \
class NAME##State : public State             \
{                                           \
  public:                               \
    NAME##State () : State(#NAME) {}      \
};


CREATE_STATE(WaitCmd);
CREATE_STATE(WaitCppNameArg);
CREATE_STATE(WaitArNameArg);
CREATE_STATE(WaitFileName);
CREATE_STATE(WaitEol);
CREATE_STATE(TheEnd);

} // namespace filter_sm
} // namespace sm
} // namespace udr

#endif // UDR_SM_FILTER_STATES_H

