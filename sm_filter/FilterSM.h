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

    bool IsRunning() const;
    void ProcessTextToken(const std::string & text_token);
    void ProcessEndOfLine();
    void ProcessEndOfFile();

  private:

    using EventPtr = std::unique_ptr<udr::sm::Event>;
    EventPtr m_create_event(const std::string & text_token) const;

};

} // namespace filter_sm
} // namespace sm
} // namespace udr

#endif // UDR_SM_FILTER_STATE_MACHINE_H

