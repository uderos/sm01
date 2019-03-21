#include <memory>
#include "FilterSM.h"
#include "FilterSMEvents.h"
#include "FilterSMStates.h"

namespace udr {
namespace sm {
namespace filter_sm {


FilterSM::FilterSM() : 
  StateMachine("MakeFilterSM", 
               std::make_unique<StateWaitCmd>())
{
}


} // namespace filter_sm
} // namespace sm
} // namespace udr

