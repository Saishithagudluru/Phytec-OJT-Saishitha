DESCRIPTION = "Simple hello application"
LICENSE = "saishitha"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://name.c"

S = "${WORKDIR}"

#DEPENDS = "mystatic"

do_compile() {
	${CC} name.c ${LDFLAGS} -o hello
}	

do_install() {
	install -d ${D}${bindir}
	install -m 0755 hello ${D}${bindir}
}
