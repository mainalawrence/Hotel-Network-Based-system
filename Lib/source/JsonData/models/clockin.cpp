#include "clockin.h"

namespace JsonData {
namespace Models {
Clockin::Clockin(QObject *parent) : QObject(parent)
{

}

ClockinDetails *Clockin::createClock()
{
    auto clock=new ClockinDetails(this);
    if(clock!=nullptr){
        clocklist.append(clock);
        emit clockAdded(clock);
    }
    return clock;
}

bool Clockin::deleteClock(ClockinDetails *clock)
{
    if(clocklist.contains(clock)){
        emit clockRemoved(clock);
        clocklist.removeOne(clock);
        delete clock;
        return true;
    }
    return false;
}

Clockin::ClockLists Clockin::getClocklist() const
{
    return clocklist;
}
}}
