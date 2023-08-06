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
    Q_PROPERTY(bool selected READ Selected WRITE SetSelected)
    Q_PROPERTY(int selected_x READ SelectedX WRITE SetSelectedX)
    Q_PROPERTY(int selected_y READ SelectedY WRITE SetSelectedY)
    Q_PROPERTY(int selected_piece_x READ SelectedPieceX WRITE SetSelectedPieceX)
    Q_PROPERTY(int selected_piece_y READ SelectedPieceY WRITE SetSelectedPieceY)
    Q_PROPERTY(QString chessboard_image READ GetChessBoardImage)
    Q_PROPERTY(int cell_count READ CellCount CONSTANT)
    QML_ELEMENT
public:
    ChessBoard();
    Q_INVOKABLE void startGame(const QString& mode);
    Q_INVOKABLE QString getImage(size_t posx, size_t posy);
    Q_INVOKABLE bool isYourPiece(size_t posx, size_t posy);
    Q_INVOKABLE QList<QList<int>> validMoves();
    Q_INVOKABLE void move();
    void SetDefaultBoard(QSharedPointer<Player> p1 = nullptr, QSharedPointer<Player> p2 = nullptr);
    bool IsCheck(QSharedPointer<Player> p) const;
    bool Selected() const noexcept { return m_selected; }
    void SetSelected(bool new_selected_val) { m_selected = new_selected_val; }
    int SelectedX() const noexcept { return m_selected_x; }
    void SetSelectedX(int new_selected_x_val) { m_selected_x = new_selected_x_val; }
    int SelectedY() const noexcept { return m_selected_y; }
    void SetSelectedY(int new_selected_y_val) { m_selected_y = new_selected_y_val; }
    int SelectedPieceX() const noexcept { return m_selected_piece_x; }
    void SetSelectedPieceX(int new_selected_x_val) { m_selected_piece_x = new_selected_x_val; }
    int SelectedPieceY() const noexcept { return m_selected_piece_y; }
    void SetSelectedPieceY(int new_selected_y_val) { m_selected_piece_y = new_selected_y_val; }
    int CellCount() const noexcept { return m_cell_count; }
    QString GetChessBoardImage() const;

signals:
    void gameStarted();
    void check();

private:
    bool started = false;
    bool is_check = false;
    bool is_checkmate = false;
    bool m_selected = false;
    int m_selected_x;
    int m_selected_y;
    int m_selected_piece_x;
    int m_selected_piece_y;
    const int m_cell_count = 8;
    QString chessboard_white_bottom = "qrc:/Assets/chessboard_white_bottom.png";
    QString chessboard_black_bottom = "qrc:/Assets/chessboard_black_bottom.png";
    Mode mode;
    QSharedPointer<Player> p1 = nullptr;
    QSharedPointer<Player> p2 = nullptr;
    QSharedPointer<ChessPiece> board[8][8];
};

}

#endif // CHESSBOARD_H
