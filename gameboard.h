#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <QAbstractListModel>
#include <vector>

class GameBoard : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(int dimension READ dimension CONSTANT)
    Q_PROPERTY(int hiddenElementValue READ hiddenElementValue CONSTANT)
public:
    static constexpr size_t DEFAULT_DIMENSION  {4};
    GameBoard (size_t board_dimension = DEFAULT_DIMENSION,
               QObject *parent = nullptr);

    struct Tile {
        size_t value {};
        Tile& operator= (const size_t new_value){
            value = new_value;
            return *this;
        }
        bool operator==(const size_t other) {
            return other == value;
        }
        bool operator==(const Tile &other) const {
            return other.value == value;
        }
    };

    void shuffle();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    size_t dimension() const;
    size_t hiddenElementValue() const;
    Q_INVOKABLE bool move (int index);
    using Position = std::pair<size_t, size_t>;

signals:
    void tileMoved();
    void solved();

private:
    std::vector<Tile> m_rawBoard;
    const size_t m_dimension;
    const size_t m_boardSize;
    const size_t m_hiddenElementValue;

    bool isBoardValid() const;
    bool isSolved() const;
    bool isPositionValid(const size_t position) const;
    Position getRowCol(size_t index) const;
};

#endif // GAMEBOARD_H
