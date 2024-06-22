/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -i QtGui/private/qspi_struct_marshallers_p.h -a deviceeventcontroller_adaptor.h:deviceeventcontroller_adaptor.cpp /build/qt6-base/src/qtbase/src/gui/accessible/linux/dbusxml/DeviceEventController.xml
 *
 * qdbusxml2cpp is Copyright (C) The Qt Company Ltd. and other contributors.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef DEVICEEVENTCONTROLLER_ADAPTOR_H
#define DEVICEEVENTCONTROLLER_ADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
#include "QtGui/private/qspi_struct_marshallers_p.h"
#include <QtCore/qcontainerfwd.h>

/*
 * Adaptor class for interface org.a11y.atspi.DeviceEventController
 */
class DeviceEventControllerAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.a11y.atspi.DeviceEventController")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"org.a11y.atspi.DeviceEventController\">\n"
"    <method name=\"NotifyListenersSync\">\n"
"      <arg direction=\"in\" type=\"(uinnisb)\" name=\"event\"/>\n"
"      <arg direction=\"out\" type=\"b\"/>\n"
"      <annotation value=\"QSpiDeviceEvent\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n"
"    </method>\n"
"    <method name=\"NotifyListenersAsync\">\n"
"      <arg direction=\"in\" type=\"(uinnisb)\" name=\"event\"/>\n"
"      <annotation value=\"QSpiDeviceEvent\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    DeviceEventControllerAdaptor(QObject *parent);
    ~DeviceEventControllerAdaptor() override;

public: // PROPERTIES
public Q_SLOTS: // METHODS
    void NotifyListenersAsync(const QSpiDeviceEvent &event);
    bool NotifyListenersSync(const QSpiDeviceEvent &event);
Q_SIGNALS: // SIGNALS
};

#endif
