#include "BucketDelegate.h"
#include <QComboBox>
#include <Qstring>

BucketDelegate::BucketDelegate(QObject *parent)
	: QStyledItemDelegate(parent)
{}

BucketDelegate::~BucketDelegate()
{}

QWidget* BucketDelegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	QComboBox* box = new QComboBox(parent);
	box->addItem("ap-shanghai");
	box->addItem("ap-beijing");
	box->addItem("ap-chengdu");
	box->setFrame(false);
	return box;
}

void BucketDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
	QComboBox* box = static_cast<QComboBox*>(editor);
	QString text = index.data(Qt::EditRole).toString();
	box->setCurrentText(text);
}

void BucketDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
	QComboBox* box = static_cast<QComboBox*>(editor);
	model->setData(index, box->currentIndex());
}
