#ifndef MOVECOUNTER_H
#define MOVECOUNTER_H
#include <QObject>

class MoveCounter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentMovesValue READ currentMovesValue NOTIFY currentMovesValueChanged)
public:
    explicit MoveCounter(QObject *parent = nullptr);
    int currentMovesValue() const;
    Q_INVOKABLE void increment();
signals:
    void currentMovesValueChanged(int);
private:
    int m_currentMovesValue = 0;
};

#endif // MOVECOUNTER_H
