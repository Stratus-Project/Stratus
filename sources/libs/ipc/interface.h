#pragma once

#include <ipc/ipc.h>
#include <stratus-text>

Str ipc_interface_str(IpcProto proto);

Str ipc_method_str(IpcProto proto, int method);
