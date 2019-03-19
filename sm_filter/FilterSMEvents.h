#ifndef UDR_SM_FILTER_EVENTS_H
#define UDR_SM_FILTER_EVENTS_H

#include <string>
#include <sm_lib/Event.h>

namespace udr {
namespace sm {
namespace filter_rm {

enum /*class*/ eEventId 
{
  EVENT_TEXT,
  EVENT_CPP,
  EVENT_AR,
  EVENT_CPP_NAME_TAG,
  EVENT_AR_NAME_TAG,
  EVENT_EOL,
  EVENT_EOF
};


#define CREATE_EVENT_NO_DATA(EVENT_ID)                                  \
class Event#EVENT_ID : public EventBase<(EVENT_ID)>                     \
{                                                                       \
  public:                                                               \
    Event#EVENT_ID() : EventBase<(EVENT_ID)>() {}                       \
};

#define CREATE_EVENT_WITH_DATA(EVENT_ID, DATA_TYPE)                       \
class Event#EVENT_ID : public EventBaseWithData<(EVENT_ID), std::string>  \
{                                                                         \
  public:                                                                 \
    Event#EVENT_ID(const DATA_TYPE & data) :                              \
      EventBaseWithData<(EVENT_ID), DATA_TYPE>(data) {}                   \
};

CREATE_EVENT_WITH_DATA(eEventId::EVENT_TEXT, std::string);
CREATE_EVENT_NO_DATA(eEventId::EVENT_CPP);
CREATE_EVENT_NO_DATA(eEventId::EVENT_AR);
CREATE_EVENT_NO_DATA(eEventId::EVENT_CPP_NAME_TAG);
CREATE_EVENT_NO_DATA(eEventId::EVENT_AR_NAME_TAG);
CREATE_EVENT_NO_DATA(eEventId::EVENT_EOL);
CREATE_EVENT_NO_DATA(eEventId::EVENT_EOF);


}; // namespace filter_rm
}; // namespace sm
}; // namespace udr

#endif // UDR_SM_FILTER_EVENTS_H

