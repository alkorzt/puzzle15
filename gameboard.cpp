#include "gameboard.h"
#include <algorithm>
#include <random>

namespace  {
    bool isAdjacent (GameBoard::Position f, GameBoard::Position s)
    {
        if (f == s){
            return false;
        }

        const auto calc_distance = [](size_t pos1, size_t pos2){
            int distance = static_cast<int>(pos1);
            distance -= static_cast<int>(pos2);
            distance = std::abs(distance);
            return distance;
        };

        bool result {false};

        if (f.first == s.first) {
            int distance = calc_distance (f.second, s.second);
            if (distance == 1) {
                result = true;
            }
        } else if (f.second == s.second) {
            int distance = calc_distance (f.first, s.first);
            if (distance == 1) {
                result = true;
            }
        }
        return result;
    }
}


GameBoard::GameBoard(size_t board_dimension, QObject *parent):
    QAbstractListModel {parent},
    m_dimension {board_dimension},
    m_boardSize {board_dimension * board_dimension},
    m_hiddenElementValue {m_boardSize}
{
    m_rawBoard.resize(m_boardSize);
    std::iota(m_rawBoard.begin(), m_rawBoard.end(), 1);
    shuffle();
}

void GameBoard::shuffle()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 generator(seed);

    do {
        std::shuffle(m_rawBoard.begin(), m_rawBoard.end(), generator);
    } while (!isBoardValid());
}

int GameBoard::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_boardSize);
}

QVariant GameBoard::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return {};
    }

    const auto index_row {static_cast<size_t>(index.row())};

    if (!isPositionValid(index_row)) {
        return {};
    }

    return QVariant(static_cast<int>(m_rawBoard[index_row].value));
}

size_t GameBoard::dimension() const
{
    return m_dimension;
}

size_t GameBoard::hiddenElementValue() const
{
    return m_hiddenElementValue;
}

bool GameBoard::move(int index)
{
    if (!isPositionValid(static_cast<size_t>(index))) {
        return false;
    }

    Position positionOfIndex {getRowCol(index)};

    auto hiddenElementIterator = std::find(m_rawBoard.begin(),
                                           m_rawBoard.end(),
                                           m_hiddenElementValue);

    Q_ASSERT(hiddenElementIterator != m_rawBoard.end());
    Position hiddenElementPosition {getRowCol(std::distance(
                                                  m_rawBoard.begin(),
                                                  hiddenElementIterator))};

    if (!isAdjacent(positionOfIndex, hiddenElementPosition)) {
        return false;
    }

    std::swap(hiddenElementIterator->value, m_rawBoard[index].value);
    emit dataChanged(createIndex(0, 0), createIndex(m_boardSize, 0));
    return true;
}

bool GameBoard::isBoardValid() const
{
    int inv {0};
    for (size_t i {0}; i < m_boardSize; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (m_rawBoard[j].value > m_rawBoard[i].value){
                ++inv;
            }
        }
    }

    const size_t start_point = 1;

    for (size_t i = 0; i < m_boardSize; ++i) {
        if (m_rawBoard[i].value == m_boardSize){
                inv += start_point + i / m_dimension;
         }
    }

    return (inv % 2) == 0;
}

bool GameBoard::isPositionValid(const size_t position) const
{
    return position < m_boardSize;
}

GameBoard::Position GameBoard::getRowCol(size_t index) const
{
    size_t row = index / m_dimension;
    size_t col = index % m_dimension;

    return std::make_pair(row, col);
}
