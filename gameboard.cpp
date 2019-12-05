#include "gameboard.h"
#include <algorithm>
#include <random>

GameBoard::GameBoard(size_t board_dimension, QObject *parent):
    QAbstractListModel {parent},
    m_dimension {board_dimension},
    m_boardSize {board_dimension * board_dimension}
{
    m_rawBoard.resize(m_boardSize);
    std::iota(m_rawBoard.begin(), m_rawBoard.end(), 1);
    shuffle();
}

void GameBoard::shuffle()
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 generator(seed);
    std::shuffle(m_rawBoard.begin(), m_rawBoard.end(), generator);
}

int GameBoard::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_boardSize);
}
