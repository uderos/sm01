#ifndef UDR_SM_FILTER_STATES_H
#define UDR_SM_FILTER_STATES_H

#include <sm_lib/State.h>

namespace udr {
namespace sm {
namespace filter_rm {


CRETE_STATE(WaitCmd);
CRETE_STATE(WaitCppNameArg);
CRETE_STATE(WaitArNameArg);
CRETE_STATE(WaitFileName);
CRETE_STATE(WaitEol);
CRETE_STATE(TheEnd);


} // namespace filter_sm
} // namespace sm
} // namespace udr

#endif // UDR_SM_FILTER_STATES_H

