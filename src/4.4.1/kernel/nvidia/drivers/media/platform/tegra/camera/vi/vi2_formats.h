/*
 * NVIDIA Tegra Video Input Device Driver VI2 formats
 *
 * Copyright (c) 2017-2019, NVIDIA CORPORATION.  All rights reserved.
 *
 * Author: Bhanu Murthy V <bmurthyv@nvidia.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __VI2_FORMATS_H_
#define __VI2_FORMATS_H_


#define VC_CODE_VI2     1   /* CCC - new code for VC MIPI drivers */
#define VC_RGGB10P_VI2  0   /* CCC - set packed 10-bit bayer RGGB format */

#include <media/tegra_camera_core.h>

/*
 * These go into the TEGRA_VI_CSI_n_IMAGE_DEF registers bits 23:16
 * Output pixel memory format for the VI channel.
 */
enum tegra_image_format {
    TEGRA_IMAGE_FORMAT_T_L8 = 16,

    TEGRA_IMAGE_FORMAT_T_R16_I = 32,
    TEGRA_IMAGE_FORMAT_T_B5G6R5,
    TEGRA_IMAGE_FORMAT_T_R5G6B5,
    TEGRA_IMAGE_FORMAT_T_A1B5G5R5,
    TEGRA_IMAGE_FORMAT_T_A1R5G5B5,
    TEGRA_IMAGE_FORMAT_T_B5G5R5A1,
    TEGRA_IMAGE_FORMAT_T_R5G5B5A1,
    TEGRA_IMAGE_FORMAT_T_A4B4G4R4,
    TEGRA_IMAGE_FORMAT_T_A4R4G4B4,
    TEGRA_IMAGE_FORMAT_T_B4G4R4A4,
    TEGRA_IMAGE_FORMAT_T_R4G4B4A4,

    TEGRA_IMAGE_FORMAT_T_A8B8G8R8 = 64,
    TEGRA_IMAGE_FORMAT_T_A8R8G8B8,
    TEGRA_IMAGE_FORMAT_T_B8G8R8A8,
    TEGRA_IMAGE_FORMAT_T_R8G8B8A8,
    TEGRA_IMAGE_FORMAT_T_A2B10G10R10,
    TEGRA_IMAGE_FORMAT_T_A2R10G10B10,
    TEGRA_IMAGE_FORMAT_T_B10G10R10A2,
    TEGRA_IMAGE_FORMAT_T_R10G10B10A2,

    TEGRA_IMAGE_FORMAT_T_A8Y8U8V8 = 193,
    TEGRA_IMAGE_FORMAT_T_V8U8Y8A8,

    TEGRA_IMAGE_FORMAT_T_A2Y10U10V10 = 197,
    TEGRA_IMAGE_FORMAT_T_V10U10Y10A2,

    TEGRA_IMAGE_FORMAT_T_Y8_U8__Y8_V8 = 200,
    TEGRA_IMAGE_FORMAT_T_Y8_V8__Y8_U8,
    TEGRA_IMAGE_FORMAT_T_U8_Y8__V8_Y8,
    TEGRA_IMAGE_FORMAT_T_V8_Y8__U8_Y8,

    TEGRA_IMAGE_FORMAT_T_Y8__U8__V8_N444 = 224,
    TEGRA_IMAGE_FORMAT_T_Y8__U8V8_N444,
    TEGRA_IMAGE_FORMAT_T_Y8__V8U8_N444,
    TEGRA_IMAGE_FORMAT_T_Y8__U8__V8_N422,
    TEGRA_IMAGE_FORMAT_T_Y8__U8V8_N422,
    TEGRA_IMAGE_FORMAT_T_Y8__V8U8_N422,
    TEGRA_IMAGE_FORMAT_T_Y8__U8__V8_N420,
    TEGRA_IMAGE_FORMAT_T_Y8__U8V8_N420,
    TEGRA_IMAGE_FORMAT_T_Y8__V8U8_N420,
    TEGRA_IMAGE_FORMAT_T_X2Lc10Lb10La10,
    TEGRA_IMAGE_FORMAT_T_A2R6R6R6R6R6,
};

static const struct tegra_video_format vi2_video_formats[] = {
    /* RAW 6: TODO */

    /* RAW 7: TODO */

    /* RAW 8 */
    TEGRA_VIDEO_FORMAT(RAW8, 8, SRGGB8_1X8, 1, 1, T_L8,
                RAW8, SRGGB8, "RGRG.. GBGB.."),
    TEGRA_VIDEO_FORMAT(RAW8, 8, SGRBG8_1X8, 1, 1, T_L8,
                RAW8, SGRBG8, "GRGR.. BGBG.."),
    TEGRA_VIDEO_FORMAT(RAW8, 8, SGBRG8_1X8, 1, 1, T_L8,
                RAW8, SGBRG8, "GBGB.. RGRG.."),
    TEGRA_VIDEO_FORMAT(RAW8, 8, SBGGR8_1X8, 1, 1, T_L8,
                RAW8, SBGGR8, "BGBG.. GRGR.."),

#if VC_CODE_VI2
    TEGRA_VIDEO_FORMAT(RAW8, 8, Y8_1X8, 1, 1, T_L8,
                RAW8, GREY, "GRAY8"),
//        MEDIA_BUS_FMT_Y8_1X8,     // Gray 8-bit
//        V4L2_COLORSPACE_RAW,
//        V4L2_PIX_FMT_GREY,

    /* RAW 10 */
    TEGRA_VIDEO_FORMAT(RAW10, 10, Y10_1X10, 2, 1, T_R16_I,
                RAW10, Y10, "GRAY10"),
//        MEDIA_BUS_FMT_Y10_1X10,   // Gray 10-bit
//        V4L2_COLORSPACE_RAW,
//        V4L2_PIX_FMT_Y10,
//        V4L2_PIX_FMT_Y10BPACK    v4l2_fourcc('Y', '1', '0', 'B') /* 10  Greyscale bit-packed */

    /* RAW 12 */
    TEGRA_VIDEO_FORMAT(RAW12, 12, Y12_1X12, 2, 1, T_R16_I,
                RAW12, Y12, "GRAY12"),
//        MEDIA_BUS_FMT_Y12_1X12,   // Gray 12-bit
//        V4L2_COLORSPACE_RAW,
//        V4L2_PIX_FMT_Y12,
#endif

    /* RAW 10 */
#if VC_RGGB10P_VI2
    TEGRA_VIDEO_FORMAT(RAW10, 10, SRGGB10_1X10, 2, 1, T_R16_I,
                RAW10, SRGGB10P, "RGRG.. GBGB.."),
//        MEDIA_BUS_FMT_SRGGB10_1X10,
//        V4L2_COLORSPACE_SRGB,
//        V4L2_PIX_FMT_SRGGB10P,
#else
    TEGRA_VIDEO_FORMAT(RAW10, 10, SRGGB10_1X10, 2, 1, T_R16_I,
                RAW10, SRGGB10, "RGRG.. GBGB.."),
#endif
    TEGRA_VIDEO_FORMAT(RAW10, 10, SGRBG10_1X10, 2, 1, T_R16_I,
                RAW10, SGRBG10, "GRGR.. BGBG.."),
    TEGRA_VIDEO_FORMAT(RAW10, 10, SGBRG10_1X10, 2, 1, T_R16_I,
                RAW10, SGBRG10, "GBGB.. RGRG.."),
    TEGRA_VIDEO_FORMAT(RAW10, 10, SBGGR10_1X10, 2, 1, T_R16_I,
                RAW10, SBGGR10, "BGBG.. GRGR.."),

    /* RAW 10 Packed format */
    TEGRA_VIDEO_FORMAT(RAW10, 10, XBGGR10P_3X10, 4, 3, T_X2Lc10Lb10La10,
                RAW10, XBGGR10P, "BGBG.. GRGR.."),
    TEGRA_VIDEO_FORMAT(RAW10, 10, XRGGB10P_3X10, 4, 3, T_X2Lc10Lb10La10,
                RAW10, XRGGB10P, "RGRG.. GBGB.."),

    /* RAW 12 */
    TEGRA_VIDEO_FORMAT(RAW12, 12, SRGGB12_1X12, 2, 1, T_R16_I,
                RAW12, SRGGB12, "RGRG.. GBGB.."),
    TEGRA_VIDEO_FORMAT(RAW12, 12, SGRBG12_1X12, 2, 1, T_R16_I,
                RAW12, SGRBG12, "GRGR.. BGBG.."),
    TEGRA_VIDEO_FORMAT(RAW12, 12, SGBRG12_1X12, 2, 1, T_R16_I,
                RAW12, SGBRG12, "GBGB.. RGRG.."),
    TEGRA_VIDEO_FORMAT(RAW12, 12, SBGGR12_1X12, 2, 1, T_R16_I,
                RAW12, SBGGR12, "BGBG.. GRGR.."),

    /* RGB888 */
    TEGRA_VIDEO_FORMAT(RGB888, 24, RGB888_1X24, 4, 1, T_A8R8G8B8,
                RGB888, ABGR32, "BGRA-8-8-8-8"),
    TEGRA_VIDEO_FORMAT(RGB888, 24, RGB888_1X32_PADHI, 4, 1, T_A8B8G8R8,
                RGB888, RGB32, "RGB-8-8-8-8"),

    /* YUV422 */
    TEGRA_VIDEO_FORMAT(YUV422, 16, UYVY8_1X16, 2, 1, T_U8_Y8__V8_Y8,
                YUV422_8, UYVY, "YUV 4:2:2"),
    TEGRA_VIDEO_FORMAT(YUV422, 16, VYUY8_1X16, 2, 1, T_V8_Y8__U8_Y8,
                YUV422_8, VYUY, "YUV 4:2:2"),
    TEGRA_VIDEO_FORMAT(YUV422, 16, YUYV8_1X16, 2, 1, T_Y8_U8__Y8_V8,
                YUV422_8, YUYV, "YUV 4:2:2"),
    TEGRA_VIDEO_FORMAT(YUV422, 16, YVYU8_1X16, 2, 1, T_Y8_V8__Y8_U8,
                YUV422_8, YVYU, "YUV 4:2:2"),
    TEGRA_VIDEO_FORMAT(YUV422, 16, UYVY8_1X16, 1, 1, T_Y8__V8U8_N422,
                YUV422_8, NV16, "NV16"),
    TEGRA_VIDEO_FORMAT(YUV422, 16, UYVY8_2X8, 2, 1, T_U8_Y8__V8_Y8,
                YUV422_8, UYVY, "YUV 4:2:2 UYVY"),
    TEGRA_VIDEO_FORMAT(YUV422, 16, VYUY8_2X8, 2, 1, T_V8_Y8__U8_Y8,
                YUV422_8, VYUY, "YUV 4:2:2 VYUY"),
    TEGRA_VIDEO_FORMAT(YUV422, 16, YUYV8_2X8, 2, 1, T_Y8_U8__Y8_V8,
                YUV422_8, YUYV, "YUV 4:2:2 YUYV"),
    TEGRA_VIDEO_FORMAT(YUV422, 16, YVYU8_2X8, 2, 1, T_Y8_V8__Y8_U8,
                YUV422_8, YVYU, "YUV 4:2:2 YVYU"),
};
#endif
