#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QQmlEngine>
#include "Pieces/chesspiece.h"
#include "player.h"

namespace qtchess {

enum Mode {
    Offline,
    Online,
    Computer
};

class ChessBoard : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool selected READ getSelected WRITE setSelected)
    Q_PROPERTY(int selectedX READ getSelectedX WRITE setSelectedX)
    Q_PROPERTY(int selectedY READ getSelectedY WRITE setSelectedY)
    Q_PROPERTY(int selectedPieceX READ getSelectedPieceX WRITE setSelectedPieceX)
    Q_PROPERTY(int selectedPieceY READ getSelectedPieceY WRITE setSelectedPieceY)
    Q_PROPERTY(QString chessBoardImage READ getChessBoardImage)
    Q_PROPERTY(int cellCount READ getCellCount CONSTANT)
    QML_ELEMENT
public:
    ChessBoard();
    Q_INVOKABLE void startGame(const QString& mode);
    Q_INVOKABLE QString getImage(size_t posX, size_t posY);
    Q_INVOKABLE bool isYourPiece(size_t posX, size_t posY);
    Q_INVOKABLE QList<QList<int>> validMoves();
    Q_INVOKABLE void move();
    void setDefaultBoard(QSharedPointer<Player> p1 = nullptr, QSharedPointer<Player> p2 = nullptr);
    bool isCheck(QSharedPointer<Player> p) const;
    bool getSelected() const noexcept
    {
        return mSelected;
    }
    void setSelected(bool selected)
    {
        mSelected = selected;
    }
    int getSelectedX() const noexcept
    {
        return mSelectedX;
    }
    void setSelectedX(int selectedX)
    {
        mSelectedX = selectedX;
    }
    int getSelectedY() const noexcept
    {
        return mSelectedY;
    }
    void setSelectedY(int selectedY)
    {
        mSelectedY = selectedY;
    }
    int getSelectedPieceX() const noexcept
    {
        return mSelectedPieceX;
    }
    void setSelectedPieceX(int selectedPieceX)
    {
        mSelectedPieceX = selectedPieceX;
    }
    int getSelectedPieceY() const noexcept
    {
        return mSelectedPieceY;
    }
    void setSelectedPieceY(int selectedPieceY)
    {
        mSelectedPieceY = selectedPieceY;
    }
    int getCellCount() const noexcept
    {
        return mCellCount;
    }
    QString getChessBoardImage() const;

signals:
    void gameStarted();
    void declareCheck();

private:
    bool started = false;
    bool check = false;
    bool isCheckmate = false;
    bool mSelected = false;
    int mSelectedX = 0;
    int mSelectedY = 0;
    int mSelectedPieceX = 0;
    int mSelectedPieceY = 0;
    const int mCellCount = 8;
    QString chessBoardWhiteBottom = "qrc:/Assets/chessboard_white_bottom.png";
    QString chessboardBlackBottom = "qrc:/Assets/chessboard_black_bottom.png";
    Mode mode;
    QSharedPointer<Player> p1 = nullptr;
    QSharedPointer<Player> p2 = nullptr;
    QSharedPointer<ChessPiece> board[8][8];
};

}

#endif // CHESSBOARD_H
