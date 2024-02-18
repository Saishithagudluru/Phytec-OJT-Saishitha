SUMMARY = "A small boot image"
LICENSE = "MIT"
inherit core-image
# Core files for basic console boot
#IMAGE_INSTALL = "packagegroup-core-boot"
#IMAGE_ROOTFS_SIZE ?= "8192"
#Add our needed applications
IMAGE_INSTALL += "usbutils"
IMAGE_INSTALL += "python3"
IMAGE_INSTALL += "packagegroup-core-buildessential"
IMAGE_FEATURE = " ssh-server-dropbear"
IMAGE_FEATURES += "splash"
IMAGE_FEATURES = "read-only-rootfs"
#IMAGE_INSTALL += "name"
