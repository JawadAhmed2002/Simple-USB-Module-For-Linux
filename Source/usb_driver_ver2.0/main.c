#include "device_file.h"	// include the device file from the current directory
#include <linux/init.h>       /* module_init, module_exit */
#include <linux/module.h>     /* version info, MODULE_LICENSE, MODULE_AUTHOR, printk() */
#include <linux/usb.h>

#define IS_NEW_METHOD_USED  ( 1 )


#define USB_VENDOR_ID       ( 0x23a9 )      //USB device's vendor ID
#define USB_PRODUCT_ID      ( 0xef18 )      //USB device's product ID


#define PRINT_USB_INTERFACE_DESCRIPTOR( i )                         \
{                                                                   \
    pr_info("USB_INTERFACE_DESCRIPTOR:\n");                         \
    pr_info("-----------------------------\n");                     \
    pr_info("bLength: 0x%x\n", i.bLength);                          \
    pr_info("bDescriptorType: 0x%x\n", i.bDescriptorType);          \
    pr_info("bInterfaceNumber: 0x%x\n", i.bInterfaceNumber);        \
    pr_info("bAlternateSetting: 0x%x\n", i.bAlternateSetting);      \
    pr_info("bNumEndpoints: 0x%x\n", i.bNumEndpoints);              \
    pr_info("bInterfaceClass: 0x%x\n", i.bInterfaceClass);          \
    pr_info("bInterfaceSubClass: 0x%x\n", i.bInterfaceSubClass);    \
    pr_info("bInterfaceProtocol: 0x%x\n", i.bInterfaceProtocol);    \
    pr_info("iInterface: 0x%x\n", i.iInterface);                    \
    pr_info("\n");                                                  \
}

#define PRINT_USB_ENDPOINT_DESCRIPTOR( e )                          \
{                                                                   \
    pr_info("USB_ENDPOINT_DESCRIPTOR:\n");                          \
    pr_info("------------------------\n");                          \
    pr_info("bLength: 0x%x\n", e.bLength);                          \
    pr_info("bDescriptorType: 0x%x\n", e.bDescriptorType);          \
    pr_info("bEndPointAddress: 0x%x\n", e.bEndpointAddress);        \
    pr_info("bmAttributes: 0x%x\n", e.bmAttributes);                \
    pr_info("wMaxPacketSize: 0x%x\n", e.wMaxPacketSize);            \
    pr_info("bInterval: 0x%x\n", e.bInterval);                      \
    pr_info("\n");                                                  \
}

/*
** This function will be called when USB device is inserted.
*/
static int etx_usb_probe(struct usb_interface *interface,
                        const struct usb_device_id *id)
{
    unsigned int i;
    unsigned int endpoints_count;
    struct usb_host_interface *iface_desc = interface->cur_altsetting;

    dev_info(&interface->dev, "USB Driver Probed: Vendor ID : 0x%02x,\t"
             "Product ID : 0x%02x\n", id->idVendor, id->idProduct);
             
    endpoints_count = iface_desc->desc.bNumEndpoints;
    
    PRINT_USB_INTERFACE_DESCRIPTOR(iface_desc->desc);
    
     for ( i = 0; i < endpoints_count; i++ ) {
          PRINT_USB_ENDPOINT_DESCRIPTOR(iface_desc->endpoint[i].desc);
     }
    return 0;  //return 0 indicates we are managing this device
}

/*
** This function will be called when USB device is removed.
*/
static void etx_usb_disconnect(struct usb_interface *interface)
{
    dev_info(&interface->dev, "USB Driver Disconnected\n");
}

//usb_device_id provides a list of different types of USB devices that the driver supports
const struct usb_device_id etx_usb_table[] = {
    { USB_DEVICE( USB_VENDOR_ID, USB_PRODUCT_ID ) },    //Put USB device's Vendor and Product ID
    { } /* Terminating entry */
};
MODULE_DEVICE_TABLE(usb, etx_usb_table);

//The structure needs to do is register with the linux subsystem
static struct usb_driver etx_usb_driver = {
    .name       = "Namal USB Driver",
    .probe      = etx_usb_probe,
    .disconnect = etx_usb_disconnect,
    .id_table   = etx_usb_table,
};



/*===============================================================================================*/
static int simple_driver_init(void)
{
    int result = 0;
    printk( KERN_NOTICE "Namal_USB_Driver: Initialization started\n" );
    result = register_device();
    usb_register(&etx_usb_driver);
    return result;
}

/*===============================================================================================*/
static void simple_driver_exit(void)
{
    printk( KERN_NOTICE "Namal_USB_Driver: Exiting\n" );
    unregister_device();
    usb_deregister(&etx_usb_driver);
}
/*===============================================================================================*/
// call the above functions
module_init(simple_driver_init);
module_exit(simple_driver_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jawad Ahmed <jawad2019@namal.edu.pk>");
MODULE_DESCRIPTION("A simple device driver - USB Driver");
MODULE_VERSION("2.0");
