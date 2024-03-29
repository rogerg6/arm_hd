/*
 * 参考/drviers/hid/usbhid/usbmouse.c
 */
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb/input.h>
#include <linux/hid.h>

static struct usb_device_id usb_mouse_as_key_id_table [] = {
	{ USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT,
		USB_INTERFACE_PROTOCOL_MOUSE) },
	{ }	/* Terminating entry */
};

static int usb_mouse_as_key_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
	struct usb_device *dev = interface_to_usbdev(intf);
	
	printk("usb_mouse_as_key_probe\n");
	printk("bcdUSB = 0x%x\n", dev->descriptor.bcdUSB);
	printk("Vid    = 0x%x\n", dev->descriptor.idVendor);
	printk("Pid    = 0x%x\n", dev->descriptor.idProduct);
	
	return 0;
}

static void usb_mouse_as_key_disconnect(struct usb_interface *intf)
{
	printk("usb_mouse_as_key_disconnect\n");
}

static struct usb_driver usb_mouse_as_key_driver = {
	.name		= "usb_mouse_as_key",
	.probe		= usb_mouse_as_key_probe,
	.disconnect	= usb_mouse_as_key_disconnect,
	.id_table	= usb_mouse_as_key_id_table,
};

static int usb_mouse_as_key_init(void)
{
	usb_register(&usb_mouse_as_key_driver);
	return 0;
}

static void usb_mouse_as_key_exit(void)
{
	usb_deregister(&usb_mouse_as_key_driver);
}


module_init(usb_mouse_as_key_init);
module_exit(usb_mouse_as_key_exit);

MODULE_LICENSE("GPL");


