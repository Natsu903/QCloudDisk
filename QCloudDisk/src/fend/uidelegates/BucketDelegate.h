#pragma once

#include <QStyledItemDelegate>

class BucketDelegate  : public QStyledItemDelegate
{
	Q_OBJECT

public:
	BucketDelegate(QObject *parent=nullptr);
	~BucketDelegate();

	QWidget* createEditor(QWidget* parent,const QStyleOptionViewItem& option,const QModelIndex& index) const override;
	void setEditorData(QWidget* editor, const QModelIndex& index) const override;
	void setModelData(QWidget* editor,QAbstractItemModel* model,const QModelIndex& index) const override;
};
