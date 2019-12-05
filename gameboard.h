#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <QAbstractListModel>
#include <vector>

class GameBoard : public QAbstractListModel {
    Q_OBJECT
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
    };

    void shuffle();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    std::vector<Tile> m_rawBoard;
    const size_t m_dimension;
    const size_t m_boardSize;
};

#endif // GAMEBOARD_H
