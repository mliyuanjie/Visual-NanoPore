#include <consolelinedit.h>

ConsoleLinEdit::ConsoleLinEdit(QWidget* p) : QLineEdit(p) {
	connect(this, SIGNAL(returnPressed()), this, SLOT(addhistory()));
	history.push_back("");
	it = history.end();
}

void ConsoleLinEdit::keyReleaseEvent(QKeyEvent* event) {
	switch (event->key())
	{
	case Qt::Key_Up:
		if (it == history.begin()) {
			it = std::prev(history.end());
		}
		else {
			it = std::prev(it);
		}
		this->setText(*it);
		break;
	case Qt::Key_Down:
		if (history.size() == 0)
			return;
		if (it == history.end() || std::next(it) == history.end())
			it = history.begin();
		else {
			it = next(it);
		}
		this->setText(*it);
		break;
	case Qt::Key_Control:
		emit sendcomp(this->text());
		break;
	default:
		QLineEdit::keyReleaseEvent(event);
	}
	
}

void ConsoleLinEdit::addhistory() {
	if (this->text().size() == 0)
		return;
	history.push_back(this->text());
	if (history.size() > 50) {
		history.pop_front();
	}
	it = history.end();
}