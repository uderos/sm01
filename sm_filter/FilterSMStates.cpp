#include "FilterSMStates.h"

namespace udr {
namespace sm {
namespace filter_rm {

DefaultState::DefaultState(const std::string & name) : udr::sm::State(name)
{
  ; // Install default event handler
}


} // namespace filter_sm
} // namespace sm
} // namespace udr

