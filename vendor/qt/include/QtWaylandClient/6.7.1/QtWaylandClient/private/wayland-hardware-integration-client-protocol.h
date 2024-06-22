/* Generated by wayland-scanner 1.22.0 */

#ifndef HARDWARE_INTEGRATION_CLIENT_PROTOCOL_H
#define HARDWARE_INTEGRATION_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client-core.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_hardware_integration The hardware_integration protocol
 * @section page_ifaces_hardware_integration Interfaces
 * - @subpage page_iface_qt_hardware_integration - compostors communicates supported buffer sharing extensions
 * @section page_copyright_hardware_integration Copyright
 * <pre>
 *
 * Copyright (C) 2015 The Qt Company Ltd.
 * SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
 * </pre>
 */
struct qt_hardware_integration;

#ifndef QT_HARDWARE_INTEGRATION_INTERFACE
#define QT_HARDWARE_INTEGRATION_INTERFACE
/**
 * @page page_iface_qt_hardware_integration qt_hardware_integration
 * @section page_iface_qt_hardware_integration_desc Description
 *
 * Using this protocol the compositor can signal to clients which buffer sharing extensions
 * the client should use
 * @section page_iface_qt_hardware_integration_api API
 * See @ref iface_qt_hardware_integration.
 */
/**
 * @defgroup iface_qt_hardware_integration The qt_hardware_integration interface
 *
 * Using this protocol the compositor can signal to clients which buffer sharing extensions
 * the client should use
 */
extern const struct wl_interface qt_hardware_integration_interface;
#endif

/**
 * @ingroup iface_qt_hardware_integration
 * @struct qt_hardware_integration_listener
 */
struct qt_hardware_integration_listener {
	/**
	 */
	void (*client_backend)(void *data,
			       struct qt_hardware_integration *qt_hardware_integration,
			       const char *name);
	/**
	 */
	void (*server_backend)(void *data,
			       struct qt_hardware_integration *qt_hardware_integration,
			       const char *name);
};

/**
 * @ingroup iface_qt_hardware_integration
 */
static inline int
qt_hardware_integration_add_listener(struct qt_hardware_integration *qt_hardware_integration,
				     const struct qt_hardware_integration_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) qt_hardware_integration,
				     (void (**)(void)) listener, data);
}

/**
 * @ingroup iface_qt_hardware_integration
 */
#define QT_HARDWARE_INTEGRATION_CLIENT_BACKEND_SINCE_VERSION 1
/**
 * @ingroup iface_qt_hardware_integration
 */
#define QT_HARDWARE_INTEGRATION_SERVER_BACKEND_SINCE_VERSION 1


/** @ingroup iface_qt_hardware_integration */
static inline void
qt_hardware_integration_set_user_data(struct qt_hardware_integration *qt_hardware_integration, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) qt_hardware_integration, user_data);
}

/** @ingroup iface_qt_hardware_integration */
static inline void *
qt_hardware_integration_get_user_data(struct qt_hardware_integration *qt_hardware_integration)
{
	return wl_proxy_get_user_data((struct wl_proxy *) qt_hardware_integration);
}

static inline uint32_t
qt_hardware_integration_get_version(struct qt_hardware_integration *qt_hardware_integration)
{
	return wl_proxy_get_version((struct wl_proxy *) qt_hardware_integration);
}

/** @ingroup iface_qt_hardware_integration */
static inline void
qt_hardware_integration_destroy(struct qt_hardware_integration *qt_hardware_integration)
{
	wl_proxy_destroy((struct wl_proxy *) qt_hardware_integration);
}

#ifdef  __cplusplus
}
#endif

#endif
