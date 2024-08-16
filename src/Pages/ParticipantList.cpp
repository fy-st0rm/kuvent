#include "Pages/ParticipantList.h"

void ParticipantList::onAttach()
{
	getBaseWidget()->setStyleSheet(
		"background-color:" + Theme::dashBg + ";"
		"border-radius: 15px;"
	);
    setupUI();
    setCentralWidget(scrollArea);
    setLayout(containerLayout);
}

void ParticipantList::setupUI()
{
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setStyleSheet(
        "QScrollArea { border: none; }"
        "QScrollBar:vertical { border: none; margin: 0px 0px 0px 0px; }"
        "QScrollBar::handle:vertical { border-radius: 5px; background: #FFFFFF; }"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { background: none; height: 0px; }"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical { background: none; }"
    );
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    containerWidget = new QWidget();
    containerLayout = new QVBoxLayout(containerWidget);
    containerLayout->setSpacing(10);
    containerLayout->setContentsMargins(10, 10, 10, 10);

    setupHeader();
    setupLabels();
    scrollArea->setWidget(containerWidget);
}

void ParticipantList::setupHeader()
{
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    containerLayout->addLayout(hLayout1);

    QLabel *eventName = new QLabel(this);
		eventName->setText(QString(
			"<span style='color: " + Theme::red + ";'>🔴</span>  %1"
		).arg(
			QString::fromStdString(m_event["NAME"].asString())
		));
    eventName->setStyleSheet("font-weight: bold; font-size: 12pt; color: #000000;");
    hLayout1->addWidget(eventName);

    // Close button
    closeButton = new QToolButton();
    closeButton->setIcon(QIcon("assets/images/close.png"));
    closeButton->setIconSize(QSize(20, 20));
    closeButton->setContentsMargins(0, 0, 0, 0);
    closeButton->setStyleSheet("border: none;");
    connect(closeButton, &QToolButton::clicked, this, &ParticipantList::onCloseClick);
    hLayout1->addWidget(closeButton, 0, Qt::AlignRight);
}

void ParticipantList::setupLabels()
{
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    containerLayout->addLayout(hLayout2);

    QLabel *organizerName = new QLabel(QString::fromStdString(m_event["ORGANIZER"].asString()), this);
    organizerName->setStyleSheet("font-size: 10pt; color: #000000;");
    hLayout2->addWidget(organizerName);

    containerLayout->addSpacing(50);

    QHBoxLayout *hLayout3 = new QHBoxLayout();
    containerLayout->addLayout(hLayout3);

    hLayout3->addSpacing(40);
    addLabelToLayout(hLayout3, "Username");
    addLabelToLayout(hLayout3, "Program Batch");
    addLabelToLayout(hLayout3, "Email");
    addLabelToLayout(hLayout3, "Contact No.");
}

void ParticipantList::addLabelToLayout(QHBoxLayout *layout, const QString &text)
{
    QLabel *label = new QLabel(text, this);
    label->setStyleSheet("font-weight: bold; font-size: 10pt; color: #000000;");
    layout->addWidget(label);
}

void ParticipantList::onEntry()
{
    displayParticipants();
    containerLayout->addStretch();
}

void ParticipantList::onExit()
{
    clearParticipantDetails();

    // Remove the last item (stretch)
    QLayoutItem* item = containerLayout->takeAt(containerLayout->count() - 1);
    if (QWidget* widget = item->widget()) {
        delete widget;
    } else {
        delete item;
    }
}

void ParticipantList::clearParticipantDetails()
{
    while (!m_details.empty()) {
        delete m_details.back();
        m_details.pop_back();
    }
}

void ParticipantList::displayParticipants()
{
    httplib::Result res = app->client->Get("/get_participants/" + m_event["ID"].asString());

    if (!handleResponseErrors(res, "Participants fetching Error")) {
        return;
    }

    Json::Value data;
    Json::Reader reader;
    reader.parse(res->body, data);

    for (const auto &user_id : data["participants"]) {
        displayParticipant(user_id.asString());
    }
}

void ParticipantList::displayParticipant(const std::string &user_id)
{
    httplib::Result res = app->client->Get("/get_profile/" + user_id);

    if (!handleResponseErrors(res, "Profile fetching Error")) {
        return;
    }

    Json::Value user_data;
    Json::Reader reader;
    reader.parse(res->body, user_data);

    MyEventsDetails* user_details = new MyEventsDetails(
        QString::fromStdString(user_data["username"].asString()),
        QString::fromStdString(user_data["batch"].asString()),
        QString::fromStdString(user_data["email"].asString()),
        QString::fromStdString(user_data["number"].asString())
    );
    m_details.push_back(user_details);
    containerLayout->addWidget(user_details);
}

bool ParticipantList::handleResponseErrors(const httplib::Result &res, const QString &errorTitle)
{
    if (!res) {
        QMessageBox::critical(this, "Connection Error", "Cannot connect to the server. Please check your connection and try again later.");
        return false;
    }

    if (res->status != httplib::StatusCode::OK_200) {
        QMessageBox::warning(this, errorTitle, QString::fromStdString(res->body));
        return false;
    }

    return true;
}

void ParticipantList::onCloseClick()
{
    pg_switcher->switchPage("MyEventsPage");
}
