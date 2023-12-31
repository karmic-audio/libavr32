#ifndef _USB_HID_H_
#define _USB_HID_H_


#include "compiler.h"
#include "uhc.h"
#include "types.h"

// HID event data is is simply a bitfield indicating which bytes have changed in the frame.
// application handler can look up the relevant bytes in the frame data directly.
#define HID_FRAME_MAX_BYTES 64
#define HID_FRAME_IDX_MASK 31

// HID device was plugged or unplugged
extern void hid_change(uhc_device_t* dev, u8 plug);

// test dirty flag for given byte in packet
//extern u8 hid_get_byte_flag(u32 dirty, u8 byte);
extern u8 hid_get_byte_flag(u8 byte);

// parse frame and spawn events
extern void hid_parse_frame(u8* frame, u8 size);

// get the frame data
extern const volatile u8* hid_get_frame_data(void);

// get the bitfield of dirty bytes
extern const volatile u32 hid_get_frame_dirty(void);

// clear the bitfield of dirty bytes
extern void hid_clear_frame_dirty(void);

// get the frame size
extern const volatile u8 hid_get_frame_size(void);


#endif // h guard
