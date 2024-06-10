#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>

int main(int argc, char **argv)
{
	QApplication app (argc, argv);
	
	QPushButton button;
	button.setText("My text");
	button.setToolTip("A tooltip");
	button.show();
	
	return app.exec();
}
