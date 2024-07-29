#pragma once

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>

#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtGui/QIcon>

#include "Page.h"
#include "Widgets/PageSwitcher.h"
#include "httplib.h"

enum AccountType {
	PARTICIPANT,
	ORGANIZER
};

static AccountType stringToAccount(const std::string& str) {
	if (str == "Participant")
		return PARTICIPANT;
	return ORGANIZER;
}

struct AppData {
	std::string id;
	std::string username;
	std::string email;
	std::string number;
	AccountType account_type;
	std::string batch;
	std::string pfp;
};

class Application {
public:
	httplib::Client* client;

public:
	~Application();

public:
	virtual void onAttach() = 0;

	inline QWidget* getBaseWidget() {
		return m_main_widget;
	}

	inline void setAppData(const AppData& app_data) {
		m_app_data = app_data;
	}

	inline AppData getAppData() {
		return m_app_data;
	}

	int run(const std::string& title, int argc, char** argv);

	template<typename T>
	void addPage(const std::string& name) {
		m_pg_switcher->addPage<T>(name);
	}

	void switchPage(const std::string& name) {
		m_pg_switcher->switchPage(name);
	}

private:
	void init_qt();

private:
	QApplication* m_app;
	QWidget* m_main_widget;
	QVBoxLayout* m_main_layout;
	PageSwitcher* m_pg_switcher;

	AppData m_app_data;
};
