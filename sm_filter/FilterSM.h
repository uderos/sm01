#ifndef UDR_SM_FILTER_STATE_MACHINE_H
#define UDR_SM_FILTER_STATE_MACHINE_H

#include <sm_lib/StateMachine.h>
#include "FilterSMEvents.h"
#include "FilterSMStates.h"

namespace udr {
namespace sm {
namespace filter_sm {

class FilterSM : public StateMachine
{
  public:
    FilterSM();
    virtual ~FilterSM() = default;

  private:

};

} // namespace filter_sm
} // namespace sm
} // namespace udr

#endif // UDR_SM_FILTER_STATE_MACHINE_H

