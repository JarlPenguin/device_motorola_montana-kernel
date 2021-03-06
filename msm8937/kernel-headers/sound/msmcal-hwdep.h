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
#ifndef _CALIB_HWDEP_H
#define _CALIB_HWDEP_H
#define WCD9XXX_CODEC_HWDEP_NODE 1000
enum wcd_cal_type {
  WCD9XXX_MIN_CAL,
  WCD9XXX_ANC_CAL = WCD9XXX_MIN_CAL,
  WCD9XXX_MAD_CAL,
  WCD9XXX_MBHC_CAL,
  WCD9XXX_VBAT_CAL,
  BG_CODEC_MIC_CAL,
  BG_CODEC_SPEAKER_CAL,
  WCD9XXX_MAX_CAL,
};
#define BG_CAL_SUPPORT BG_CODEC_SPEAKER_CAL
struct wcdcal_ioctl_buffer {
  __u32 size;
  __u8 * buffer;
  enum wcd_cal_type cal_type;
};
#define SNDRV_CTL_IOCTL_HWDEP_CAL_TYPE _IOW('U', 0x1, struct wcdcal_ioctl_buffer)
#endif
