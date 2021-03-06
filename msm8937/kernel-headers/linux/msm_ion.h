/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _MSM_ION_H
#define _MSM_ION_H
#include "ion.h"
#define ION_BIT(nr) (1UL << (nr))
enum msm_ion_heap_types {
  ION_HEAP_TYPE_MSM_START = ION_HEAP_TYPE_CUSTOM + 1,
  ION_HEAP_TYPE_SECURE_DMA = ION_HEAP_TYPE_MSM_START,
  ION_HEAP_TYPE_SYSTEM_SECURE,
  ION_HEAP_TYPE_HYP_CMA,
  ION_HEAP_TYPE_SECURE_CARVEOUT,
};
enum ion_heap_ids {
  INVALID_HEAP_ID = - 1,
  ION_CP_MM_HEAP_ID = 8,
  ION_SECURE_HEAP_ID = 9,
  ION_SECURE_DISPLAY_HEAP_ID = 10,
  ION_CP_MFC_HEAP_ID = 12,
  ION_SPSS_HEAP_ID = 13,
  ION_SECURE_CARVEOUT_HEAP_ID = 14,
  ION_CP_WB_HEAP_ID = 16,
  ION_QSECOM_TA_HEAP_ID = 19,
  ION_CAMERA_HEAP_ID = 20,
  ION_SYSTEM_CONTIG_HEAP_ID = 21,
  ION_ADSP_HEAP_ID = 22,
  ION_PIL1_HEAP_ID = 23,
  ION_SF_HEAP_ID = 24,
  ION_SYSTEM_HEAP_ID = 25,
  ION_PIL2_HEAP_ID = 26,
  ION_QSECOM_HEAP_ID = 27,
  ION_AUDIO_HEAP_ID = 28,
  ION_MM_FIRMWARE_HEAP_ID = 29,
  ION_HEAP_ID_RESERVED = 31
};
#define ION_IOMMU_HEAP_ID ION_SYSTEM_HEAP_ID
#define ION_HEAP_TYPE_IOMMU ION_HEAP_TYPE_SYSTEM
#define ION_SPSS_HEAP_ID ION_SPSS_HEAP_ID
enum ion_fixed_position {
  NOT_FIXED,
  FIXED_LOW,
  FIXED_MIDDLE,
  FIXED_HIGH,
};
enum cp_mem_usage {
  VIDEO_BITSTREAM = 0x1,
  VIDEO_PIXEL = 0x2,
  VIDEO_NONPIXEL = 0x3,
  DISPLAY_SECURE_CP_USAGE = 0x4,
  CAMERA_SECURE_CP_USAGE = 0x5,
  MAX_USAGE = 0x6,
  UNKNOWN = 0x7FFFFFFF,
};
#define ION_FLAG_CP_TOUCH ION_BIT(17)
#define ION_FLAG_CP_BITSTREAM ION_BIT(18)
#define ION_FLAG_CP_PIXEL ION_BIT(19)
#define ION_FLAG_CP_NON_PIXEL ION_BIT(20)
#define ION_FLAG_CP_CAMERA ION_BIT(21)
#define ION_FLAG_CP_HLOS ION_BIT(22)
#define ION_FLAG_CP_SPSS_SP ION_BIT(23)
#define ION_FLAG_CP_SPSS_SP_SHARED ION_BIT(24)
#define ION_FLAG_CP_SEC_DISPLAY ION_BIT(25)
#define ION_FLAG_CP_APP ION_BIT(26)
#define ION_FLAG_CP_CAMERA_PREVIEW ION_BIT(27)
#define ION_FLAG_CP_CDSP ION_BIT(29)
#define ION_FLAG_CP_SPSS_HLOS_SHARED ION_BIT(30)
#define ION_FLAG_ALLOW_NON_CONTIG ION_BIT(28)
#define ION_FLAG_SECURE ION_BIT(ION_HEAP_ID_RESERVED)
#define ION_FLAG_POOL_FORCE_ALLOC ION_BIT(16)
#define ION_SECURE ION_FLAG_SECURE
#define ION_HEAP(bit) ION_BIT(bit)
#define ION_ADSP_HEAP_NAME "adsp"
#define ION_SYSTEM_HEAP_NAME "system"
#define ION_VMALLOC_HEAP_NAME ION_SYSTEM_HEAP_NAME
#define ION_KMALLOC_HEAP_NAME "kmalloc"
#define ION_AUDIO_HEAP_NAME "audio"
#define ION_SF_HEAP_NAME "sf"
#define ION_MM_HEAP_NAME "mm"
#define ION_CAMERA_HEAP_NAME "camera_preview"
#define ION_IOMMU_HEAP_NAME "iommu"
#define ION_MFC_HEAP_NAME "mfc"
#define ION_SPSS_HEAP_NAME "spss"
#define ION_SECURE_CARVEOUT_HEAP_NAME "secure_carveout"
#define ION_WB_HEAP_NAME "wb"
#define ION_MM_FIRMWARE_HEAP_NAME "mm_fw"
#define ION_PIL1_HEAP_NAME "pil_1"
#define ION_PIL2_HEAP_NAME "pil_2"
#define ION_QSECOM_HEAP_NAME "qsecom"
#define ION_QSECOM_TA_HEAP_NAME "qsecom_ta"
#define ION_SECURE_HEAP_NAME "secure_heap"
#define ION_SECURE_DISPLAY_HEAP_NAME "secure_display"
#define ION_SET_CACHED(__cache) ((__cache) | ION_FLAG_CACHED)
#define ION_SET_UNCACHED(__cache) ((__cache) & ~ION_FLAG_CACHED)
#define ION_IS_CACHED(__flags) ((__flags) & ION_FLAG_CACHED)
struct ion_flush_data {
  ion_user_handle_t handle;
  int fd;
  void * vaddr;
  unsigned int offset;
  unsigned int length;
};
struct ion_prefetch_regions {
  unsigned int vmid;
  size_t * sizes;
  unsigned int nr_sizes;
};
struct ion_prefetch_data {
  int heap_id;
  unsigned long len;
  struct ion_prefetch_regions * regions;
  unsigned int nr_regions;
};
#define ION_IOC_MSM_MAGIC 'M'
#define ION_IOC_CLEAN_CACHES _IOWR(ION_IOC_MSM_MAGIC, 0, struct ion_flush_data)
#define ION_IOC_INV_CACHES _IOWR(ION_IOC_MSM_MAGIC, 1, struct ion_flush_data)
#define ION_IOC_CLEAN_INV_CACHES _IOWR(ION_IOC_MSM_MAGIC, 2, struct ion_flush_data)
#define ION_IOC_PREFETCH _IOWR(ION_IOC_MSM_MAGIC, 3, struct ion_prefetch_data)
#define ION_IOC_DRAIN _IOWR(ION_IOC_MSM_MAGIC, 4, struct ion_prefetch_data)
#endif
