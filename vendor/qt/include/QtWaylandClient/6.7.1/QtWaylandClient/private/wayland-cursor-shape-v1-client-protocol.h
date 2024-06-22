/* Generated by wayland-scanner 1.22.0 */

#ifndef CURSOR_SHAPE_V1_CLIENT_PROTOCOL_H
#define CURSOR_SHAPE_V1_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client-core.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_cursor_shape_v1 The cursor_shape_v1 protocol
 * @section page_ifaces_cursor_shape_v1 Interfaces
 * - @subpage page_iface_wp_cursor_shape_manager_v1 - cursor shape manager
 * - @subpage page_iface_wp_cursor_shape_device_v1 - cursor shape for a device
 * @section page_copyright_cursor_shape_v1 Copyright
 * <pre>
 *
 * Copyright 2018 The Chromium Authors
 * Copyright 2023 Simon Ser
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * </pre>
 */
struct wl_pointer;
struct wp_cursor_shape_device_v1;
struct wp_cursor_shape_manager_v1;
struct zwp_tablet_tool_v2;

#ifndef WP_CURSOR_SHAPE_MANAGER_V1_INTERFACE
#define WP_CURSOR_SHAPE_MANAGER_V1_INTERFACE
/**
 * @page page_iface_wp_cursor_shape_manager_v1 wp_cursor_shape_manager_v1
 * @section page_iface_wp_cursor_shape_manager_v1_desc Description
 *
 * This global allows clients to set cursor images by name instead of
 * creating and attaching buffers.
 *
 * Warning! The protocol described in this file is currently in the testing
 * phase. Backward compatible changes may be added together with the
 * corresponding interface version bump. Backward incompatible changes can
 * only be done by creating a new major version of the extension.
 * @section page_iface_wp_cursor_shape_manager_v1_api API
 * See @ref iface_wp_cursor_shape_manager_v1.
 */
/**
 * @defgroup iface_wp_cursor_shape_manager_v1 The wp_cursor_shape_manager_v1 interface
 *
 * This global allows clients to set cursor images by name instead of
 * creating and attaching buffers.
 *
 * Warning! The protocol described in this file is currently in the testing
 * phase. Backward compatible changes may be added together with the
 * corresponding interface version bump. Backward incompatible changes can
 * only be done by creating a new major version of the extension.
 */
extern const struct wl_interface wp_cursor_shape_manager_v1_interface;
#endif
#ifndef WP_CURSOR_SHAPE_DEVICE_V1_INTERFACE
#define WP_CURSOR_SHAPE_DEVICE_V1_INTERFACE
/**
 * @page page_iface_wp_cursor_shape_device_v1 wp_cursor_shape_device_v1
 * @section page_iface_wp_cursor_shape_device_v1_desc Description
 *
 * This interface advertises the list of supported cursor shapes for a
 * device, and allows clients to set the cursor shape.
 * @section page_iface_wp_cursor_shape_device_v1_api API
 * See @ref iface_wp_cursor_shape_device_v1.
 */
/**
 * @defgroup iface_wp_cursor_shape_device_v1 The wp_cursor_shape_device_v1 interface
 *
 * This interface advertises the list of supported cursor shapes for a
 * device, and allows clients to set the cursor shape.
 */
extern const struct wl_interface wp_cursor_shape_device_v1_interface;
#endif

#define WP_CURSOR_SHAPE_MANAGER_V1_DESTROY 0
#define WP_CURSOR_SHAPE_MANAGER_V1_GET_POINTER 1
#define WP_CURSOR_SHAPE_MANAGER_V1_GET_TABLET_TOOL_V2 2


/**
 * @ingroup iface_wp_cursor_shape_manager_v1
 */
#define WP_CURSOR_SHAPE_MANAGER_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_wp_cursor_shape_manager_v1
 */
#define WP_CURSOR_SHAPE_MANAGER_V1_GET_POINTER_SINCE_VERSION 1
/**
 * @ingroup iface_wp_cursor_shape_manager_v1
 */
#define WP_CURSOR_SHAPE_MANAGER_V1_GET_TABLET_TOOL_V2_SINCE_VERSION 1

/** @ingroup iface_wp_cursor_shape_manager_v1 */
static inline void
wp_cursor_shape_manager_v1_set_user_data(struct wp_cursor_shape_manager_v1 *wp_cursor_shape_manager_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wp_cursor_shape_manager_v1, user_data);
}

/** @ingroup iface_wp_cursor_shape_manager_v1 */
static inline void *
wp_cursor_shape_manager_v1_get_user_data(struct wp_cursor_shape_manager_v1 *wp_cursor_shape_manager_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wp_cursor_shape_manager_v1);
}

static inline uint32_t
wp_cursor_shape_manager_v1_get_version(struct wp_cursor_shape_manager_v1 *wp_cursor_shape_manager_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) wp_cursor_shape_manager_v1);
}

/**
 * @ingroup iface_wp_cursor_shape_manager_v1
 *
 * Destroy the cursor shape manager.
 */
static inline void
wp_cursor_shape_manager_v1_destroy(struct wp_cursor_shape_manager_v1 *wp_cursor_shape_manager_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) wp_cursor_shape_manager_v1,
			 WP_CURSOR_SHAPE_MANAGER_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) wp_cursor_shape_manager_v1), WL_MARSHAL_FLAG_DESTROY);
}

/**
 * @ingroup iface_wp_cursor_shape_manager_v1
 *
 * Obtain a wp_cursor_shape_device_v1 for a wl_pointer object.
 */
static inline struct wp_cursor_shape_device_v1 *
wp_cursor_shape_manager_v1_get_pointer(struct wp_cursor_shape_manager_v1 *wp_cursor_shape_manager_v1, struct wl_pointer *pointer)
{
	struct wl_proxy *cursor_shape_device;

	cursor_shape_device = wl_proxy_marshal_flags((struct wl_proxy *) wp_cursor_shape_manager_v1,
			 WP_CURSOR_SHAPE_MANAGER_V1_GET_POINTER, &wp_cursor_shape_device_v1_interface, wl_proxy_get_version((struct wl_proxy *) wp_cursor_shape_manager_v1), 0, NULL, pointer);

	return (struct wp_cursor_shape_device_v1 *) cursor_shape_device;
}

/**
 * @ingroup iface_wp_cursor_shape_manager_v1
 *
 * Obtain a wp_cursor_shape_device_v1 for a zwp_tablet_tool_v2 object.
 */
static inline struct wp_cursor_shape_device_v1 *
wp_cursor_shape_manager_v1_get_tablet_tool_v2(struct wp_cursor_shape_manager_v1 *wp_cursor_shape_manager_v1, struct zwp_tablet_tool_v2 *tablet_tool)
{
	struct wl_proxy *cursor_shape_device;

	cursor_shape_device = wl_proxy_marshal_flags((struct wl_proxy *) wp_cursor_shape_manager_v1,
			 WP_CURSOR_SHAPE_MANAGER_V1_GET_TABLET_TOOL_V2, &wp_cursor_shape_device_v1_interface, wl_proxy_get_version((struct wl_proxy *) wp_cursor_shape_manager_v1), 0, NULL, tablet_tool);

	return (struct wp_cursor_shape_device_v1 *) cursor_shape_device;
}

#ifndef WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_ENUM
#define WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_ENUM
/**
 * @ingroup iface_wp_cursor_shape_device_v1
 * cursor shapes
 *
 * This enum describes cursor shapes.
 *
 * The names are taken from the CSS W3C specification:
 * https://w3c.github.io/csswg-drafts/css-ui/#cursor
 */
enum wp_cursor_shape_device_v1_shape {
	/**
	 * default cursor
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_DEFAULT = 1,
	/**
	 * a context menu is available for the object under the cursor
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_CONTEXT_MENU = 2,
	/**
	 * help is available for the object under the cursor
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_HELP = 3,
	/**
	 * pointer that indicates a link or another interactive element
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_POINTER = 4,
	/**
	 * progress indicator
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_PROGRESS = 5,
	/**
	 * program is busy, user should wait
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_WAIT = 6,
	/**
	 * a cell or set of cells may be selected
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_CELL = 7,
	/**
	 * simple crosshair
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_CROSSHAIR = 8,
	/**
	 * text may be selected
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_TEXT = 9,
	/**
	 * vertical text may be selected
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_VERTICAL_TEXT = 10,
	/**
	 * drag-and-drop: alias of/shortcut to something is to be created
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_ALIAS = 11,
	/**
	 * drag-and-drop: something is to be copied
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_COPY = 12,
	/**
	 * drag-and-drop: something is to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_MOVE = 13,
	/**
	 * drag-and-drop: the dragged item cannot be dropped at the current cursor location
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_NO_DROP = 14,
	/**
	 * drag-and-drop: the requested action will not be carried out
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_NOT_ALLOWED = 15,
	/**
	 * drag-and-drop: something can be grabbed
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_GRAB = 16,
	/**
	 * drag-and-drop: something is being grabbed
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_GRABBING = 17,
	/**
	 * resizing: the east border is to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_E_RESIZE = 18,
	/**
	 * resizing: the north border is to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_N_RESIZE = 19,
	/**
	 * resizing: the north-east corner is to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_NE_RESIZE = 20,
	/**
	 * resizing: the north-west corner is to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_NW_RESIZE = 21,
	/**
	 * resizing: the south border is to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_S_RESIZE = 22,
	/**
	 * resizing: the south-east corner is to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_SE_RESIZE = 23,
	/**
	 * resizing: the south-west corner is to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_SW_RESIZE = 24,
	/**
	 * resizing: the west border is to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_W_RESIZE = 25,
	/**
	 * resizing: the east and west borders are to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_EW_RESIZE = 26,
	/**
	 * resizing: the north and south borders are to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_NS_RESIZE = 27,
	/**
	 * resizing: the north-east and south-west corners are to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_NESW_RESIZE = 28,
	/**
	 * resizing: the north-west and south-east corners are to be moved
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_NWSE_RESIZE = 29,
	/**
	 * resizing: that the item/column can be resized horizontally
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_COL_RESIZE = 30,
	/**
	 * resizing: that the item/row can be resized vertically
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_ROW_RESIZE = 31,
	/**
	 * something can be scrolled in any direction
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_ALL_SCROLL = 32,
	/**
	 * something can be zoomed in
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_ZOOM_IN = 33,
	/**
	 * something can be zoomed out
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_ZOOM_OUT = 34,
};
#endif /* WP_CURSOR_SHAPE_DEVICE_V1_SHAPE_ENUM */

#ifndef WP_CURSOR_SHAPE_DEVICE_V1_ERROR_ENUM
#define WP_CURSOR_SHAPE_DEVICE_V1_ERROR_ENUM
enum wp_cursor_shape_device_v1_error {
	/**
	 * the specified shape value is invalid
	 */
	WP_CURSOR_SHAPE_DEVICE_V1_ERROR_INVALID_SHAPE = 1,
};
#endif /* WP_CURSOR_SHAPE_DEVICE_V1_ERROR_ENUM */

#define WP_CURSOR_SHAPE_DEVICE_V1_DESTROY 0
#define WP_CURSOR_SHAPE_DEVICE_V1_SET_SHAPE 1


/**
 * @ingroup iface_wp_cursor_shape_device_v1
 */
#define WP_CURSOR_SHAPE_DEVICE_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_wp_cursor_shape_device_v1
 */
#define WP_CURSOR_SHAPE_DEVICE_V1_SET_SHAPE_SINCE_VERSION 1

/** @ingroup iface_wp_cursor_shape_device_v1 */
static inline void
wp_cursor_shape_device_v1_set_user_data(struct wp_cursor_shape_device_v1 *wp_cursor_shape_device_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) wp_cursor_shape_device_v1, user_data);
}

/** @ingroup iface_wp_cursor_shape_device_v1 */
static inline void *
wp_cursor_shape_device_v1_get_user_data(struct wp_cursor_shape_device_v1 *wp_cursor_shape_device_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) wp_cursor_shape_device_v1);
}

static inline uint32_t
wp_cursor_shape_device_v1_get_version(struct wp_cursor_shape_device_v1 *wp_cursor_shape_device_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) wp_cursor_shape_device_v1);
}

/**
 * @ingroup iface_wp_cursor_shape_device_v1
 *
 * Destroy the cursor shape device.
 *
 * The device cursor shape remains unchanged.
 */
static inline void
wp_cursor_shape_device_v1_destroy(struct wp_cursor_shape_device_v1 *wp_cursor_shape_device_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) wp_cursor_shape_device_v1,
			 WP_CURSOR_SHAPE_DEVICE_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) wp_cursor_shape_device_v1), WL_MARSHAL_FLAG_DESTROY);
}

/**
 * @ingroup iface_wp_cursor_shape_device_v1
 *
 * Sets the device cursor to the specified shape. The compositor will
 * change the cursor image based on the specified shape.
 *
 * The cursor actually changes only if the input device focus is one of
 * the requesting client's surfaces. If any, the previous cursor image
 * (surface or shape) is replaced.
 *
 * The "shape" argument must be a valid enum entry, otherwise the
 * invalid_shape protocol error is raised.
 *
 * This is similar to the wl_pointer.set_cursor and
 * zwp_tablet_tool_v2.set_cursor requests, but this request accepts a
 * shape instead of contents in the form of a surface. Clients can mix
 * set_cursor and set_shape requests.
 *
 * The serial parameter must match the latest wl_pointer.enter or
 * zwp_tablet_tool_v2.proximity_in serial number sent to the client.
 * Otherwise the request will be ignored.
 */
static inline void
wp_cursor_shape_device_v1_set_shape(struct wp_cursor_shape_device_v1 *wp_cursor_shape_device_v1, uint32_t serial, uint32_t shape)
{
	wl_proxy_marshal_flags((struct wl_proxy *) wp_cursor_shape_device_v1,
			 WP_CURSOR_SHAPE_DEVICE_V1_SET_SHAPE, NULL, wl_proxy_get_version((struct wl_proxy *) wp_cursor_shape_device_v1), 0, serial, shape);
}

#ifdef  __cplusplus
}
#endif

#endif
