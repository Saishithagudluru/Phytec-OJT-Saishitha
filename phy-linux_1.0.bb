DESCRIPTION = "Simple kernel recipe for latest version"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
inherit kernel

SRC_URI ="https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.5.6.tar.xz;name=kernel \
	  file://defconfig "

S = "${WORKDIR}/linux-6.5.6"

SRC_URI[kernel.sha256sum] = "78e36d4214547051c24df2140f4ce09428d6c515ad9a71b38b28e8094a95d2f6"








