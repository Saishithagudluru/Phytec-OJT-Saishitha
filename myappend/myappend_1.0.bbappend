DESCRIPTION = "Simple calci application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"


SRC_URI ="file://add.c \
          file://main.c \
          file://sub.c \
          file://mul.c \
          file://header.h "

FILESEXTRAPATHS:prepend := "${THISDIR}/phy:"

S = "${WORKDIR}"


do_compile() {
    ${CC} *.c ${LDFLAGS} -o app
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 app ${D}${bindir}
}
