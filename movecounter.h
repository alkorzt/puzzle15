#ifndef MOVECOUNTER_H
#define MOVECOUNTER_H
#include <QObject>

class MoveCounter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentMovesValue READ currentMovesValue NOTIFY currentMovesValueChanged)
    Q_PROPERTY(int bestScore READ bestScore NOTIFY bestScoreChanged)
public:
    explicit MoveCounter(QObject *parent = nullptr);
    int currentMovesValue() const;
    Q_INVOKABLE void increment();
    int bestScore() const;
    Q_INVOKABLE void updateBestScore();
signals:
    void currentMovesValueChanged(int);
    void bestScoreChanged(int);
private:
    int m_currentMovesValue = 0;
};

#endif // MOVECOUNTER_H
