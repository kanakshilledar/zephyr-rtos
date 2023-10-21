# Copyright (c) 2021 Nordic Semiconductor
#
# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
sysbuild_images_order(IMAGES_FLASHING_ORDER FLASH IMAGES ${IMAGES})

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
set(domains_yaml "default: ${DEFAULT_IMAGE}")
set(domains_yaml "${domains_yaml}\nbuild_dir: ${CMAKE_BINARY_DIR}")
set(domains_yaml "${domains_yaml}\ndomains:")
foreach(image ${IMAGES})
  set(domains_yaml "${domains_yaml}\n  - name: ${image}")
  set(domains_yaml "${domains_yaml}\n    build_dir: $<TARGET_PROPERTY:${image},_EP_BINARY_DIR>")
endforeach()
<<<<<<< HEAD
=======
set(domains_yaml "${domains_yaml}\nflash_order:")
foreach(image ${IMAGES_FLASHING_ORDER})
  set(flash_cond "$<NOT:$<BOOL:$<TARGET_PROPERTY:${image},BUILD_ONLY>>>")
  set(domains_yaml "${domains_yaml}$<${flash_cond}:\n  - ${image}>")
endforeach()
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
file(GENERATE OUTPUT ${CMAKE_BINARY_DIR}/domains.yaml CONTENT "${domains_yaml}")
