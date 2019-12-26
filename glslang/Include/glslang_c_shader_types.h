﻿/**
	This code is based on the glslang_c_interface implementation by Viktor Latypov
**/

/**
BSD 2-Clause License

Copyright (c) 2019, Viktor Latypov
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/

#ifndef C_SHADER_TYPES_H_INCLUDED
#define C_SHADER_TYPES_H_INCLUDED

/* EShLanguage counterpart */
typedef enum {
    GLSLANG_STAGE_VERTEX,
    GLSLANG_STAGE_TESSCONTROL,
    GLSLANG_STAGE_TESSEVALUATION,
    GLSLANG_STAGE_GEOMETRY,
    GLSLANG_STAGE_FRAGMENT,
    GLSLANG_STAGE_COMPUTE,
    GLSLANG_STAGE_RAYGEN_NV,
    GLSLANG_STAGE_INTERSECT_NV,
    GLSLANG_STAGE_ANYHIT_NV,
    GLSLANG_STAGE_CLOSESTHIT_NV,
    GLSLANG_STAGE_MISS_NV,
    GLSLANG_STAGE_CALLABLE_NV,
    GLSLANG_STAGE_TASK_NV,
    GLSLANG_STAGE_MESH_NV,
    GLSLANG_STAGE_COUNT,
} glslang_stage_t; // would be better as stage, but this is ancient now

/* EShLanguageMask counterpart */
typedef enum {
    GLSLANG_STAGE_VERTEX_MASK = (1 << GLSLANG_STAGE_VERTEX),
    GLSLANG_STAGE_TESSCONTROL_MASK = (1 << GLSLANG_STAGE_TESSCONTROL),
    GLSLANG_STAGE_TESSEVALUATION_MASK = (1 << GLSLANG_STAGE_TESSEVALUATION),
    GLSLANG_STAGE_GEOMETRY_MASK = (1 << GLSLANG_STAGE_GEOMETRY),
    GLSLANG_STAGE_FRAGMENT_MASK = (1 << GLSLANG_STAGE_FRAGMENT),
    GLSLANG_STAGE_COMPUTE_MASK = (1 << GLSLANG_STAGE_COMPUTE),
    GLSLANG_STAGE_RAYGEN_NV_MASK = (1 << GLSLANG_STAGE_RAYGEN_NV),
    GLSLANG_STAGE_INTERSECT_NV_MASK = (1 << GLSLANG_STAGE_INTERSECT_NV),
    GLSLANG_STAGE_ANYHIT_NV_MASK = (1 << GLSLANG_STAGE_ANYHIT_NV),
    GLSLANG_STAGE_CLOSESTHIT_NV_MASK = (1 << GLSLANG_STAGE_CLOSESTHIT_NV),
    GLSLANG_STAGE_MISS_NV_MASK = (1 << GLSLANG_STAGE_MISS_NV),
    GLSLANG_STAGE_CALLABLE_NV_MASK = (1 << GLSLANG_STAGE_CALLABLE_NV),
    GLSLANG_STAGE_TASK_NV_MASK = (1 << GLSLANG_STAGE_TASK_NV),
    GLSLANG_STAGE_MESH_NV_MASK = (1 << GLSLANG_STAGE_MESH_NV),
} glslang_stage_mask_t;

/* EShSource counterpart */
typedef enum {
    GLSLANG_SOURCE_NONE,
    GLSLANG_SOURCE_GLSL,
    GLSLANG_SOURCE_HLSL,
} glslang_source_t;

/* EShClient counterpart */
typedef enum {
    GLSLANG_CLIENT_NONE,
    GLSLANG_CLIENT_VULKAN,
    GLSLANG_CLIENT_OPENGL,
} glslang_client_t;

/* EShTargetLanguage counterpart */
typedef enum {
    GLSLANG_TARGET_NONE,
    GLSLANG_TARGET_SPV,
} glslang_target_language_t;

/* SH_TARGET_ClientVersion counterpart */
typedef enum {
    GLSLANG_TARGET_VULKAN_1_0 = (1 << 22),
    GLSLANG_TARGET_VULKAN_1_1 = (1 << 22) | (1 << 12),
    GLSLANG_TARGET_OPENGL_450 = 450,
} glslang_target_client_version_t;

/* SH_TARGET_LanguageVersion counterpart */
typedef enum {
    GLSLANG_TARGET_SPV_1_0 = (1 << 16),
    GLSLANG_TARGET_SPV_1_1 = (1 << 16) | (1 << 8),
    GLSLANG_TARGET_SPV_1_2 = (1 << 16) | (2 << 8),
    GLSLANG_TARGET_SPV_1_3 = (1 << 16) | (3 << 8),
    GLSLANG_TARGET_SPV_1_4 = (1 << 16) | (4 << 8),
    GLSLANG_TARGET_SPV_1_5 = (1 << 16) | (5 << 8),
} glslang_target_language_version_t;

/* EShExecutable counterpart */
typedef enum { GLSLANG_EX_VERTEX_FRAGMENT, GLSLANG_EX_FRAGMENT } glslang_executable_t;

/* EShOptimizationLevel counterpart  */
typedef enum {
    GLSLANG_OPT_NO_GENERATION,
    GLSLANG_OPT_NONE,
    GLSLANG_OPT_SIMPLE,
    GLSLANG_OPT_FULL,
} glslang_optimization_level_t;

/* EShTextureSamplerTransformMode counterpart */
typedef enum {
    GLSLANG_TEX_SAMP_TRANS_KEEP,
    GLSLANG_TEX_SAMP_TRANS_UPGRADE_TEXTURE_REMOVE_SAMPLER,
} glslang_texture_sampler_transform_mode_t;

/* EShMessages counterpart */
typedef enum {
    GLSLANG_MSG_DEFAULT_BIT = 0,
    GLSLANG_MSG_RELAXED_ERRORS_BIT = (1 << 0),
    GLSLANG_MSG_SUPPRESS_WARNINGS_BIT = (1 << 1),
    GLSLANG_MSG_AST_BIT = (1 << 2),
    GLSLANG_MSG_SPV_RULES_BIT = (1 << 3),
    GLSLANG_MSG_VULKAN_RULES_BIT = (1 << 4),
    GLSLANG_MSG_ONLY_PREPROCESSOR_BIT = (1 << 5),
    GLSLANG_MSG_READ_HLSL_BIT = (1 << 6),
    GLSLANG_MSG_CASCADING_ERRORS_BIT = (1 << 7),
    GLSLANG_MSG_KEEP_UNCALLED_BIT = (1 << 8),
    GLSLANG_MSG_HLSL_OFFSETS_BIT = (1 << 9),
    GLSLANG_MSG_DEBUG_INFO_BIT = (1 << 10),
    GLSLANG_MSG_HLSL_ENABLE_16BIT_TYPES_BIT = (1 << 11),
    GLSLANG_MSG_HLSL_LEGALIZATION_BIT = (1 << 12),
    GLSLANG_MSG_HLSL_DX9_COMPATIBLE_BIT = (1 << 13),
    GLSLANG_MSG_BUILTIN_SYMBOL_TABLE_BIT = (1 << 14),
} glslang_messages_t;

/* EShReflectionOptions counterpart */
typedef enum {
    GLSLANG_REFLECTION_DEFAULT_BIT = 0,
    GLSLANG_REFLECTION_STRICT_ARRAY_SUFFIX_BIT = (1 << 0),
    GLSLANG_REFLECTION_BASIC_ARRAY_SUFFIX_BIT = (1 << 1),
    GLSLANG_REFLECTION_INTERMEDIATE_IOO_BIT = (1 << 2),
    GLSLANG_REFLECTION_SEPARATE_BUFFERS_BIT = (1 << 3),
    GLSLANG_REFLECTION_ALL_BLOCK_VARIABLES_BIT = (1 << 4),
    GLSLANG_REFLECTION_UNWRAP_IO_BLOCKS_BIT = (1 << 5),
} glslang_reflection_options_t;

/* EProfile counterpart (from Versions.h) */
typedef enum {
    GLSLANG_BAD_PROFILE = 0,
    GLSLANG_NO_PROFILE = (1 << 0),
    GLSLANG_CORE_PROFILE = (1 << 1),
    GLSLANG_COMPATIBILITY_PROFILE = (1 << 2),
    GLSLANG_ES_PROFILE = (1 << 3)
} glslang_profile_t;

#endif
