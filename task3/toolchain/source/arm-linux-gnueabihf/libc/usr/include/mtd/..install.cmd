cmd_/home/tcwg-buildslave/workspace/tcwg-make-release_1/_build/sysroots/arm-linux-gnueabihf/usr/include/mtd/.install := /bin/bash scripts/headers_install.sh /home/tcwg-buildslave/workspace/tcwg-make-release_1/_build/sysroots/arm-linux-gnueabihf/usr/include/mtd ./include/uapi/mtd inftl-user.h mtd-abi.h mtd-user.h nftl-user.h ubi-user.h; /bin/bash scripts/headers_install.sh /home/tcwg-buildslave/workspace/tcwg-make-release_1/_build/sysroots/arm-linux-gnueabihf/usr/include/mtd ./include/mtd ; /bin/bash scripts/headers_install.sh /home/tcwg-buildslave/workspace/tcwg-make-release_1/_build/sysroots/arm-linux-gnueabihf/usr/include/mtd ./include/generated/uapi/mtd ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/tcwg-buildslave/workspace/tcwg-make-release_1/_build/sysroots/arm-linux-gnueabihf/usr/include/mtd/$$F; done; touch /home/tcwg-buildslave/workspace/tcwg-make-release_1/_build/sysroots/arm-linux-gnueabihf/usr/include/mtd/.install
