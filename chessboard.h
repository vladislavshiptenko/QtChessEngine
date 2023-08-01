#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QQmlEngine>

class ChessBoard : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    ChessBoard();
};

#endif // CHESSBOARD_H
