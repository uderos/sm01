#ifndef UDR_SM_FILTER_EVENTS_H
#define UDR_SM_FILTER_EVENTS_H

#include <string>
#include <sm_lib/Event.h>

namespace udr {
namespace sm {
namespace filter_rm {

enum eEventId 
{
  EVENT_TEXT,
  EVENT_CPP,
  EVENT_AR,
  EVENT_CPP_NAME_TAG,
  EVENT_AR_NAME_TAG,
  EVENT_EOL,
  EVENT_EOF
};


#define CREATE_EVENT_NO_DATA(NAME)                                      \
class Event#NAME : public Event                                         \
{                                                                       \
  Event#NAME() :                                                        \
    FilterSMEventBase(eEventId::EVENT_#NAME, "Event#NAME") {}           \
};

#define CREATE_EVENT_WITH_DATA(NAME, DATA_TYPE)                         \
class Event#NAME : public EventWithData<DATA_TYPE>                      \
{                                                                       \
  Event#NAME(const FilterSMEventBase::data_t & data) :                  \
    FilterSMEventBase(eEventId::EVENT_#NAME, "Event#NAME", data) {}     \
};

CREATE_EVENT_WITH_DATA(EVENT_TEXT, std::string);
CREATE_EVENT_NO_DATA(EVENT_CPP);
CREATE_EVENT_NO_DATA(EVENT_AR);
CREATE_EVENT_NO_DATA(EVENT_CPP_NAME_TAG);
CREATE_EVENT_NO_DATA(EVENT_AR_NAME_TAG);
CREATE_EVENT_NO_DATA(EVENT_EOL);
CREATE_EVENT_NO_DATA(EVENT_EOF);


}; // namespace filter_rm
}; // namespace sm
}; // namespace udr

#endif // UDR_SM_FILTER_EVENTS_H

