#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <QAbstractListModel>
#include <vector>

class GameBoard : public QAbstractListModel {
    Q_OBJECT
public:
    GameBoard ();

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
private:
    std::vector<Tile> m_rawBoard;
};

#endif // GAMEBOARD_H
