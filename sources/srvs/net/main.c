#include <bal/hw.h>
#include <stratus-debug>
#include <protos/boot.h>
#include "bal/abi/types.h"
#include <stratus-net>
#include <stratus-base>
#include <bal/abi.h>
#include <bal/boot.h>
#include <elf/elf.h>
#include "interface.h"
#include "pci.h"

int ipc_component_main(IpcComponent *self)
{
    log$("Hello from the net server!");

    uint8_t payload[60] = { 0 };
    EthernetFrameHeader hdr = {
        .ethertype = be$(be_uint16_t, ETHERNET_ETHERTYPE_ARP),
        .mac_dst = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}
    };
    EthernetFrame frame = ethernet_make_frame(hdr, payload, 60);
    vec_foreach(v, &interfaces)
    {
                v->driver->send(v->ctx, frame.frame, frame.size);
    }

    BrIpcArgs ipc;
    ipc.flags = BR_IPC_RECV | BR_IPC_BLOCK;
    ipc.deadline = BR_DEADLINE_INFINITY;

    while (br_ipc(&ipc) == BR_SUCCESS)
    {
        BrMsg msg = ipc.msg;

        log$("Receive IPC from {}", msg.from.id);
        if (msg.from.id == BR_ID_EVENT && msg.event.type == BR_EVENT_IRQ)
        {
            vec_foreach(v, &interfaces)
            {
                v->driver->handle(v->ctx);
            }

            br_ack(&(BrAckArgs){
                .event = msg.event
            });
        }
        else
        {
            log$("Unknown message!");
        }
    }
    return 0;
}