/* Generated by wayland-scanner 1.22.0 */

#ifndef SERVER_BUFFER_EXTENSION_CLIENT_PROTOCOL_H
#define SERVER_BUFFER_EXTENSION_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client-core.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_server_buffer_extension The server_buffer_extension protocol
 * @section page_ifaces_server_buffer_extension Interfaces
 * - @subpage page_iface_qt_server_buffer - buffers managed by the compositor
 * @section page_copyright_server_buffer_extension Copyright
 * <pre>
 *
 * Copyright (C) 2015 The Qt Company Ltd.
 * SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
 * </pre>
 */
struct qt_server_buffer;

#ifndef QT_SERVER_BUFFER_INTERFACE
#define QT_SERVER_BUFFER_INTERFACE
/**
 * @page page_iface_qt_server_buffer qt_server_buffer
 * @section page_iface_qt_server_buffer_desc Description
 *
 * Server buffer is an extension which makes it possible to share a
 * buffer created by the compositor to share it with arbitrary
 * clients. These types of buffers are intended to be read only
 * buffers for clients, but this is an implementation detail.
 *
 * Server buffers main purpose is to help implement caches
 * @section page_iface_qt_server_buffer_api API
 * See @ref iface_qt_server_buffer.
 */
/**
 * @defgroup iface_qt_server_buffer The qt_server_buffer interface
 *
 * Server buffer is an extension which makes it possible to share a
 * buffer created by the compositor to share it with arbitrary
 * clients. These types of buffers are intended to be read only
 * buffers for clients, but this is an implementation detail.
 *
 * Server buffers main purpose is to help implement caches
 */
extern const struct wl_interface qt_server_buffer_interface;
#endif

#define QT_SERVER_BUFFER_RELEASE 0


/**
 * @ingroup iface_qt_server_buffer
 */
#define QT_SERVER_BUFFER_RELEASE_SINCE_VERSION 1

/** @ingroup iface_qt_server_buffer */
static inline void
qt_server_buffer_set_user_data(struct qt_server_buffer *qt_server_buffer, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) qt_server_buffer, user_data);
}

/** @ingroup iface_qt_server_buffer */
static inline void *
qt_server_buffer_get_user_data(struct qt_server_buffer *qt_server_buffer)
{
	return wl_proxy_get_user_data((struct wl_proxy *) qt_server_buffer);
}

static inline uint32_t
qt_server_buffer_get_version(struct qt_server_buffer *qt_server_buffer)
{
	return wl_proxy_get_version((struct wl_proxy *) qt_server_buffer);
}

/** @ingroup iface_qt_server_buffer */
static inline void
qt_server_buffer_destroy(struct qt_server_buffer *qt_server_buffer)
{
	wl_proxy_destroy((struct wl_proxy *) qt_server_buffer);
}

/**
 * @ingroup iface_qt_server_buffer
 */
static inline void
qt_server_buffer_release(struct qt_server_buffer *qt_server_buffer)
{
	wl_proxy_marshal_flags((struct wl_proxy *) qt_server_buffer,
			 QT_SERVER_BUFFER_RELEASE, NULL, wl_proxy_get_version((struct wl_proxy *) qt_server_buffer), 0);
}

#ifdef  __cplusplus
}
#endif

#endif
