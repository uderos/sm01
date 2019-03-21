#include <functional>
#include "FilterSMEvents.h"
#include "FilterSMStates.h"

namespace udr {
namespace sm {
namespace filter_sm {

DefaultState::DefaultState(const std::string & name) : udr::sm::State(name)
{
  RegisterEventHandler(eEventId::EVENT_EOF, std::bind(&DefaultState::m_EOF_handler, this, std::placeholders::_1));
}

udr::sm::StatePtr DefaultState::m_EOF_handler(const udr::sm::Event & event)
{
  return std::move(std::make_unique<StateTheEnd>());
}

} // namespace filter_sm
} // namespace sm
} // namespace udr

