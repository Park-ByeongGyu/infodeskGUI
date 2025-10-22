#include "buttonDelegate.h"
#include <QPainter>
#include <QPixmap>

void ButtonDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option,
                           const QModelIndex& index) const
{
    QPushButton button;
    button.setText("Click");
    button.resize(option.rect.size());
    QPixmap pixmap(option.rect.size());
    button.render(&pixmap);
    painter->drawPixmap(option.rect.topLeft(), pixmap);
}

bool ButtonDelegate::editorEvent(QEvent* event, QAbstractItemModel* model,
                                 const QStyleOptionViewItem& option,
                                 const QModelIndex& index)
{
    if (event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (option.rect.contains(mouseEvent->pos())) {
            emit buttonClicked(index.row());
        }
    }
    return true;
}
