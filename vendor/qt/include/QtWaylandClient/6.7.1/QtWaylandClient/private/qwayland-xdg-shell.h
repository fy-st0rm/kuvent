// This file was generated by qtwaylandscanner
// source file is /build/qt6-wayland/src/qtwayland/src/client/../3rdparty/protocol/xdg-shell.xml

#ifndef QT_WAYLAND_XDG_SHELL
#define QT_WAYLAND_XDG_SHELL

#include <QtWaylandClient/private/wayland-xdg-shell-client-protocol.h>
#include <QByteArray>
#include <QString>

struct wl_registry;

QT_BEGIN_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_GCC("-Wmissing-field-initializers")
QT_WARNING_DISABLE_CLANG("-Wmissing-field-initializers")
#if !defined(Q_WAYLAND_CLIENT_XDG_SHELL_EXPORT)
#  if defined(QT_SHARED) && !defined(QT_STATIC)
#    if defined(QT_BUILD_WAYLANDCLIENT_LIB)
#      define Q_WAYLAND_CLIENT_XDG_SHELL_EXPORT Q_DECL_EXPORT
#    else
#      define Q_WAYLAND_CLIENT_XDG_SHELL_EXPORT Q_DECL_IMPORT
#    endif
#  else
#    define Q_WAYLAND_CLIENT_XDG_SHELL_EXPORT
#  endif
#endif

namespace QtWayland {
    class Q_WAYLAND_CLIENT_XDG_SHELL_EXPORT xdg_wm_base
    {
    public:
        xdg_wm_base(struct ::wl_registry *registry, uint32_t id, int version);
        xdg_wm_base(struct ::xdg_wm_base *object);
        xdg_wm_base();

        virtual ~xdg_wm_base();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::xdg_wm_base *object);

        struct ::xdg_wm_base *object() { return m_xdg_wm_base; }
        const struct ::xdg_wm_base *object() const { return m_xdg_wm_base; }
        static xdg_wm_base *fromObject(struct ::xdg_wm_base *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        enum error {
            error_role = 0, // given wl_surface has another role
            error_defunct_surfaces = 1, // xdg_wm_base was destroyed before children
            error_not_the_topmost_popup = 2, // the client tried to map or destroy a non-topmost popup
            error_invalid_popup_parent = 3, // the client specified an invalid popup parent surface
            error_invalid_surface_state = 4, // the client provided an invalid surface state
            error_invalid_positioner = 5, // the client provided an invalid positioner
            error_unresponsive = 6, // the client didn’t respond to a ping event in time
        };

        void destroy();
        struct ::xdg_positioner *create_positioner();
        struct ::xdg_surface *get_xdg_surface(struct ::wl_surface *surface);
        void pong(uint32_t serial);

    protected:
        virtual void xdg_wm_base_ping(uint32_t serial);

    private:
        void init_listener();
        static const struct xdg_wm_base_listener m_xdg_wm_base_listener;
        static void handle_ping(
            void *data,
            struct ::xdg_wm_base *object,
            uint32_t serial);
        struct ::xdg_wm_base *m_xdg_wm_base;
    };

    class Q_WAYLAND_CLIENT_XDG_SHELL_EXPORT xdg_positioner
    {
    public:
        xdg_positioner(struct ::wl_registry *registry, uint32_t id, int version);
        xdg_positioner(struct ::xdg_positioner *object);
        xdg_positioner();

        virtual ~xdg_positioner();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::xdg_positioner *object);

        struct ::xdg_positioner *object() { return m_xdg_positioner; }
        const struct ::xdg_positioner *object() const { return m_xdg_positioner; }
        static xdg_positioner *fromObject(struct ::xdg_positioner *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        enum error {
            error_invalid_input = 0, // invalid input provided
        };

        enum anchor {
            anchor_none = 0,
            anchor_top = 1,
            anchor_bottom = 2,
            anchor_left = 3,
            anchor_right = 4,
            anchor_top_left = 5,
            anchor_bottom_left = 6,
            anchor_top_right = 7,
            anchor_bottom_right = 8,
        };

        enum gravity {
            gravity_none = 0,
            gravity_top = 1,
            gravity_bottom = 2,
            gravity_left = 3,
            gravity_right = 4,
            gravity_top_left = 5,
            gravity_bottom_left = 6,
            gravity_top_right = 7,
            gravity_bottom_right = 8,
        };

        enum constraint_adjustment {
            constraint_adjustment_none = 0,
            constraint_adjustment_slide_x = 1,
            constraint_adjustment_slide_y = 2,
            constraint_adjustment_flip_x = 4,
            constraint_adjustment_flip_y = 8,
            constraint_adjustment_resize_x = 16,
            constraint_adjustment_resize_y = 32,
        };

        void destroy();
        void set_size(int32_t width, int32_t height);
        void set_anchor_rect(int32_t x, int32_t y, int32_t width, int32_t height);
        void set_anchor(uint32_t anchor);
        void set_gravity(uint32_t gravity);
        void set_constraint_adjustment(uint32_t constraint_adjustment);
        void set_offset(int32_t x, int32_t y);
        void set_reactive();
        void set_parent_size(int32_t parent_width, int32_t parent_height);
        void set_parent_configure(uint32_t serial);

    private:
        struct ::xdg_positioner *m_xdg_positioner;
    };

    class Q_WAYLAND_CLIENT_XDG_SHELL_EXPORT xdg_surface
    {
    public:
        xdg_surface(struct ::wl_registry *registry, uint32_t id, int version);
        xdg_surface(struct ::xdg_surface *object);
        xdg_surface();

        virtual ~xdg_surface();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::xdg_surface *object);

        struct ::xdg_surface *object() { return m_xdg_surface; }
        const struct ::xdg_surface *object() const { return m_xdg_surface; }
        static xdg_surface *fromObject(struct ::xdg_surface *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        enum error {
            error_not_constructed = 1, // Surface was not fully constructed
            error_already_constructed = 2, // Surface was already constructed
            error_unconfigured_buffer = 3, // Attaching a buffer to an unconfigured surface
            error_invalid_serial = 4, // Invalid serial number when acking a configure event
            error_invalid_size = 5, // Width or height was zero or negative
            error_defunct_role_object = 6, // Surface was destroyed before its role object
        };

        void destroy();
        struct ::xdg_toplevel *get_toplevel();
        struct ::xdg_popup *get_popup(struct ::xdg_surface *parent, struct ::xdg_positioner *positioner);
        void set_window_geometry(int32_t x, int32_t y, int32_t width, int32_t height);
        void ack_configure(uint32_t serial);

    protected:
        virtual void xdg_surface_configure(uint32_t serial);

    private:
        void init_listener();
        static const struct xdg_surface_listener m_xdg_surface_listener;
        static void handle_configure(
            void *data,
            struct ::xdg_surface *object,
            uint32_t serial);
        struct ::xdg_surface *m_xdg_surface;
    };

    class Q_WAYLAND_CLIENT_XDG_SHELL_EXPORT xdg_toplevel
    {
    public:
        xdg_toplevel(struct ::wl_registry *registry, uint32_t id, int version);
        xdg_toplevel(struct ::xdg_toplevel *object);
        xdg_toplevel();

        virtual ~xdg_toplevel();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::xdg_toplevel *object);

        struct ::xdg_toplevel *object() { return m_xdg_toplevel; }
        const struct ::xdg_toplevel *object() const { return m_xdg_toplevel; }
        static xdg_toplevel *fromObject(struct ::xdg_toplevel *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        enum error {
            error_invalid_resize_edge = 0, // provided value is         not a valid variant of the resize_edge enum
            error_invalid_parent = 1, // invalid parent toplevel
            error_invalid_size = 2, // client provided an invalid min or max size
        };

        enum resize_edge {
            resize_edge_none = 0,
            resize_edge_top = 1,
            resize_edge_bottom = 2,
            resize_edge_left = 4,
            resize_edge_top_left = 5,
            resize_edge_bottom_left = 6,
            resize_edge_right = 8,
            resize_edge_top_right = 9,
            resize_edge_bottom_right = 10,
        };

        enum state {
            state_maximized = 1, // the surface is maximized
            state_fullscreen = 2, // the surface is fullscreen
            state_resizing = 3, // the surface is being resized
            state_activated = 4, // the surface is now activated
            state_tiled_left = 5,
            state_tiled_right = 6,
            state_tiled_top = 7,
            state_tiled_bottom = 8,
            state_suspended = 9,
        };

        enum wm_capabilities {
            wm_capabilities_window_menu = 1, // show_window_menu is available
            wm_capabilities_maximize = 2, // set_maximized and unset_maximized are available
            wm_capabilities_fullscreen = 3, // set_fullscreen and unset_fullscreen are available
            wm_capabilities_minimize = 4, // set_minimized is available
        };

        void destroy();
        void set_parent(struct ::xdg_toplevel *parent);
        void set_title(const QString &title);
        void set_app_id(const QString &app_id);
        void show_window_menu(struct ::wl_seat *seat, uint32_t serial, int32_t x, int32_t y);
        void move(struct ::wl_seat *seat, uint32_t serial);
        void resize(struct ::wl_seat *seat, uint32_t serial, uint32_t edges);
        void set_max_size(int32_t width, int32_t height);
        void set_min_size(int32_t width, int32_t height);
        void set_maximized();
        void unset_maximized();
        void set_fullscreen(struct ::wl_output *output);
        void unset_fullscreen();
        void set_minimized();

    protected:
        virtual void xdg_toplevel_configure(int32_t width, int32_t height, wl_array *states);
        virtual void xdg_toplevel_close();
        virtual void xdg_toplevel_configure_bounds(int32_t width, int32_t height);
        virtual void xdg_toplevel_wm_capabilities(wl_array *capabilities);

    private:
        void init_listener();
        static const struct xdg_toplevel_listener m_xdg_toplevel_listener;
        static void handle_configure(
            void *data,
            struct ::xdg_toplevel *object,
            int32_t width,
            int32_t height,
            wl_array *states);
        static void handle_close(
            void *data,
            struct ::xdg_toplevel *object);
        static void handle_configure_bounds(
            void *data,
            struct ::xdg_toplevel *object,
            int32_t width,
            int32_t height);
        static void handle_wm_capabilities(
            void *data,
            struct ::xdg_toplevel *object,
            wl_array *capabilities);
        struct ::xdg_toplevel *m_xdg_toplevel;
    };

    class Q_WAYLAND_CLIENT_XDG_SHELL_EXPORT xdg_popup
    {
    public:
        xdg_popup(struct ::wl_registry *registry, uint32_t id, int version);
        xdg_popup(struct ::xdg_popup *object);
        xdg_popup();

        virtual ~xdg_popup();

        void init(struct ::wl_registry *registry, uint32_t id, int version);
        void init(struct ::xdg_popup *object);

        struct ::xdg_popup *object() { return m_xdg_popup; }
        const struct ::xdg_popup *object() const { return m_xdg_popup; }
        static xdg_popup *fromObject(struct ::xdg_popup *object);

        bool isInitialized() const;

        uint32_t version() const;
        static const struct ::wl_interface *interface();

        enum error {
            error_invalid_grab = 0, // tried to grab after being mapped
        };

        void destroy();
        void grab(struct ::wl_seat *seat, uint32_t serial);
        void reposition(struct ::xdg_positioner *positioner, uint32_t token);

    protected:
        virtual void xdg_popup_configure(int32_t x, int32_t y, int32_t width, int32_t height);
        virtual void xdg_popup_popup_done();
        virtual void xdg_popup_repositioned(uint32_t token);

    private:
        void init_listener();
        static const struct xdg_popup_listener m_xdg_popup_listener;
        static void handle_configure(
            void *data,
            struct ::xdg_popup *object,
            int32_t x,
            int32_t y,
            int32_t width,
            int32_t height);
        static void handle_popup_done(
            void *data,
            struct ::xdg_popup *object);
        static void handle_repositioned(
            void *data,
            struct ::xdg_popup *object,
            uint32_t token);
        struct ::xdg_popup *m_xdg_popup;
    };
}

QT_WARNING_POP
QT_END_NAMESPACE

#endif
