#pragma once

#include <stratus-base>
#include <stratus-io>

void embed_log_prefix(IoWriter writer);

size_t embed_debug_backtrace(uintptr_t *buf, size_t cap);
