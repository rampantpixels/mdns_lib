/* mdns.c  -  mDNS library  -  Public Domain  -  2014 Mattias Jansson / Rampant Pixels
 *
 * This library provides a cross-platform mDNS and DNS-SD library in C based
 * on our foundation and network libraries. The implementation is based on RFC 6762
 * and RFC 6763.
 *
 * The latest source code maintained by Rampant Pixels is always available at
 *
 * https://github.com/rampantpixels/mdns_lib
 *
 * The foundation and network library source code maintained by Rampant Pixels
 * is always available at
 *
 * https://github.com/rampantpixels/foundation_lib
 *
 * https://github.com/rampantpixels/network_lib
 *
 * This library is put in the public domain; you can redistribute it and/or modify it without any restrictions.
 *
 */

#include <mdns/mdns.h>

#include <foundation/foundation.h>

static bool _mdns_initialized = false;

int
mdns_module_initialize(const mdns_config_t config) {
	FOUNDATION_UNUSED(config);

	if (_mdns_initialized)
		return 0;

	_mdns_initialized = true;

	return 0;
}

void
mdns_module_shutdown(void) {
	if (!_mdns_initialized)
		return;

	_mdns_initialized = false;
}

bool
mdns_module_is_initialized(void) {
	return _mdns_initialized;
}

