#ifndef UDR_SM_FILTER_STATES_H
#define UDR_SM_FILTER_STATES_H

#include <sm_lib/Event.h>
#include <sm_lib/State.h>
#include <sm_lib/StateMachine.h>

#include "FilterSMEvents.h"

namespace udr {
namespace sm {
namespace filter_rm {



CRETE_STATE(WaitCmd);
CRETE_STATE(WaitCppNameArg);
CRETE_STATE(WaitArNameArg);
CRETE_STATE(WaitFileName);
CRETE_STATE(WaitEol);

class FilterSM : public StateMachine
{
  public:
    FilterSM();
    virtual ~FilterSM() = default;

  private:

    FilterSM(const FilterSM &) = delete;
    FilterSM(FilterSM &&) = delete;

    FilterSM & operator=(const FilterSM &) = delete;
    FilterSM & operator=(FilterSM &&) = delete;

    virtual StatePtr m_process_event(const Event & event) = 0;
};



} // namespace filter_sm
} // namespace sm
} // namespace udr

#endif // UDR_SM_FILTER_STATES_H

