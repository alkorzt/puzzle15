#include "movecounter.h"
#include <QSettings>

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

int MoveCounter::bestScore() const
{
    return QSettings().value("bestScore", -1).toInt();
}

void MoveCounter::updateBestScore()
{
    const int currentBestScore = bestScore();
    if (currentBestScore <= m_currentMovesValue && currentBestScore != -1) {
        return;
    }

    QSettings().setValue("bestScore", m_currentMovesValue);
    emit bestScoreChanged(m_currentMovesValue);
}
