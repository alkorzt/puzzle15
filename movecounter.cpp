#include "movecounter.h"

MoveCounter::MoveCounter(QObject *parent):
     QObject(parent)
{

}

int MoveCounter::currentMovesValue() const
{
    return m_currentMovesValue;
}

void MoveCounter::increment()
{
    emit currentMovesValueChanged(++m_currentMovesValue);
}
