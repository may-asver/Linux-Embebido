#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <wayland-client.h>

struct wl_display * display;
struct wl_registry * registry;

/* Get Proxy objects*/
struct wl_compositor * compositor;
struct wl_shm * shm;
struct wl_shell * shell;

/* Global handler */
void registry_global_handler (void* data, struct wl_registry * registry, uint32_t id, const char * interface, uint32_t version) {
	printf("interface %s, version %d, id %d\n", interface, version, id);
	if (strcmp(interface, "wl_compositor") == 0) {
		compositor = wl_registry_bind (registry, id, &wl_compositor_interface,1);
	} else if (strcmp(interface, "wl_shm") == 0) {
		shm = wl_registry_bind(registry,id, &wl_shm_interface,1);
	} else if (strcmp(interface, "wl_shell") == 0) {
		shell = wl_registry_bind(registry, id, &wl_shell_interface, 1);
	}
}

void registry_remove_handler (void* data, struct wl_registry * registry, uint32_t id) {
	printf("Removed %d",id);
}

struct wl_registry_listener listener = {
	registry_global_handler,
	registry_remove_handler

};

int main (int argc, char * argv[]) {
	display = wl_display_connect(NULL);
	
	if (display) {
		printf("Connected to Server\n");
	} else {
		printf("Failed to connect\n");
	}
	
	registry = wl_display_get_registry(display);
	wl_registry_add_listener(registry, &listener, NULL);
	
	wl_display_dispatch(display);
	wl_display_roundtrip(display);
	
	wl_display_disconnect(display);
	
	return 0;
	
}
